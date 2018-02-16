namespace noware
{
	namespace rdbms
	{
		// cell
		class datum
		{
			public:
				enum type
				{
					null,
					bin,
					string,
					nr
				};
				
				datum (void);
				virtual ~datum (void);
				
				// data getters
				virtual void const * const operator * (void);
				virtual operator std::string const & (void);
				virtual operator cln::nr const & (void);
				
				// data setters
				virtual std::string const & operator = (std::nullptr_t const &);
				virtual std::string const & set (void const * const &/* value*/, cln::nr const &/* size*/);
				virtual std::string const & operator = (std::string const &);
				virtual std::string const & operator = (cln::nr const &);
				
				virtual cln::nr const size (void) const;
			private:
				type _type;
				
				void * _val;
				cln::nr _size;
				
				std::string _string;
				cln::nr _nr;
		};
	}
}
