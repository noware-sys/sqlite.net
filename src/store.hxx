namespace noware
{
	namespace rdbms
	{
		// data store
		// table
		class store
		{
			public:
				store (void);
				virtual ~store (void);
				
				virtual data & operator [] (std::string const &);
				
				store_dfn dfn;
				
				std::map <cln::nr/* index*/, data/* entry*/> row/*s*/;
		};
	}
}
