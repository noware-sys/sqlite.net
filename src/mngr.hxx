#include <noware/db/sqlite.hxx>
#include <noware/net/node.hxx>
#include <zmq/msg.hxx>
#include <string>

namespace sqlite
{
	//namespace rdbms
	//{
		// cluster manager
		class mngr
			: virtual public noware::net::node
		{
			public:
				std::string const static grp_dft;
				
				mngr (void);
				
				bool const start (void);
				
			public:
				//virtual bool const query (std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> &/* result*/, const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const unsigned int &/* tries_max*/ = noware::db::sqlite::tries_dft);
				
			protected:
				// handle request
				virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/);
				
				// handle reply
				virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/);// const
		};
	//}
}
