#include <noware/db/sqlite.hxx>
#include <noware/net/node.hxx>
#include <zmq/msg.hxx>
#include <string>

namespace sqlite
{
	//namespace rdbms
	//{
		// client interface
		class usr
			: virtual public noware::net::node
		{
			public:
				//std::string const static grp_dft;
				
				//bool const start (void);
			public:
				//virtual bool const query (std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> &/* result*/, const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const unsigned int &/* tries_max*/ = noware::db::sqlite::tries_dft);
				virtual bool const query (std::map <std::string/* row*/, std::map <std::string/* column*/, std::string/* cell*/>> &/* result*/, const std::string &/* query*/);
			protected:
				//virtual zmq::msg const/* result*/ aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/);
				virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, noware::net::cast const &/* src_cast*/);// const
		};
	//}
}
