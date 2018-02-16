namespace noware
{
	namespace rdbms
	{
		// definition/structure
		// when creating a table
		class store_dfn
		{
			public:
				enum ndx_ref_act
				{
					restrict,
					cascade
				};
				
				std::string descr;
				std::string ndx;
				ndx_ref_act change;
				ndx_ref_act del;
		};
	}
}
