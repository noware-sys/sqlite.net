#include "mngr.hxx"
#include "srv.cxx"
#include <noware/db/sqlite.cxx>
#include <noware/net/node.cxx>
#include <zmq/msg.cxx>

std::string const sqlite::mngr::grp_dft = "sqlite::mngr";

sqlite::mngr::mngr (void)
{
	_node.sync = false;
}

bool const sqlite::mngr::start (void)
{
	if (!noware::net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

// search through all responses from the servers
bool const/* success*/ sqlite::mngr::search (zmq::msg & result/* for client*/, zmq::msg const & response/* from server*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/)// const
{
	std::cout << "sqlite::mngr::search()" << std::endl;
	
	result = response;
	
	return true;
}

// respond to client
bool const/* success*/ sqlite::mngr::respond (zmq::msg & response/* to client*/, zmq::msg const & req/* from client*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/)
{
	std::cout << "sqlite::mngr::respond()" << std::endl;
	
	response = multival (req, sqlite::srv::grp_dft);
	//response = "22 serialization::archive 16 0 0 1 0 0 0 1 1 0 0 2 0 0 0 1 1 3 111 1 2 3 22";
	
	return true;
}
