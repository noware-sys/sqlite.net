#include "srv.hxx"
#include <noware/db/sqlite.cxx>
#include <noware/net/node.cxx>
#include <noware/serial.cxx>
#include <zmq/msg.cxx>
#include <string>
#include <map>

std::string const sqlite::srv::grp_dft = "sqlite::srv";

sqlite::srv::srv (void)
{
	db.connect ("./test.db");
}

bool const sqlite::srv::start (void)
{
	if (!db.connected ())
		return false;
	
	if (!noware::net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

bool const/* success*/ sqlite::srv::respond (zmq::msg & response, zmq::msg const & req, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/)
{
	std::cout << "sqlite::srv::respond()" << std::endl;
	
	std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> result;	// the result set
	std::map <int, std::string> args;
	unsigned int arg_ndx;
	std::string serial;
	
	// get all the arguments of the query
	// frame index 0 holds the query itself
	arg_ndx = 1;
	while (req.data.count (arg_ndx) > 0)
	{
		std::cerr << "sqlite::srv::respond()::loop::ndx=[" << arg_ndx << "]" << std::endl;
	
		args [arg_ndx - 1] = req.data [arg_ndx];
		
		++ arg_ndx;
	}
	
	std::cerr << "sqlite::srv::respond()::req.data[0]=[" << std::string (req.data [0]) << "]" << std::endl;
	
	if (!db.query (result, req.data [0]/* the query*/, args))
		return false;
	
	if (!noware::serialize <std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>>> (serial, result))
		return false;
	
	response = serial;
	
	return true;
}
