#include "usr.hxx"
#include "mngr.cxx"
#include <noware/db/sqlite.cxx>
#include <noware/net/node.cxx>
#include <noware/serial.cxx>
#include <zmq/msg.cxx>
#include <string>
#include <map>

//std::string const sqlite::usr::grp_dft = "sqlite::usr";

/*
bool const sqlite::usr::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}
*/

//bool const sqlite::usr::query (std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> & result, const std::string & query, const std::map <int, std::string> & args, const unsigned int &/* tries_max*/ = noware::db::sqlite::tries_dft)
bool const sqlite::usr::query (std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> & result, const std::string & query)
{
	std::cout << "sqlite::usr::query()" << std::endl;
	
	zmq::msg req;
	//unsigned int arg_ndx;
	std::string serial;
	
	// set all the arguments of the query
	// frame index 0 holds the query itself
	req.data [0] = query;
	////arg_ndx = 1;
	//for (std::pair <int const, std::string const> const & arg : args)
	//{
	//	req.data [arg.first + 1/* assuming 0-indexed*/] = arg.second;
	//}
	
	//noware::deserialize <std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>>> (result, multival (req, sqlite::mngr::grp_dft));
	
	serial = multival (req, sqlite::mngr::grp_dft);
	//serial = "22 serialization::archive 16 0 0 1 0 0 0 1 1 0 0 2 0 0 0 1 1 3 111 1 2 3 222";
	
	noware::deserialize <std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>>> (result, serial);
	
	std::cout << "sqlite::usr::query()::serial[" << serial << "]" << std::endl;
	
	return true;
}

//zmq::msg const/* result*/ sqlite::usr::aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/)
//{
//}

bool const/* success*/ sqlite::usr::search (zmq::msg & result, zmq::msg const & req, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/)// const
{
	result = req;
	return true;
}
