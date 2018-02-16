namespace noware
{
	namespace rdbms
	{
		// row entry record
		class data
		{
			public:
				data (void);
				virtual ~data (void);
				
				virtual datum & operator [] (std::string const &);
				
				// a single row, featuring multiple columns (cells)
				std::map <std::string/* column*/, datum/* cell*/> col/*umns*/;
		};
	}
}
