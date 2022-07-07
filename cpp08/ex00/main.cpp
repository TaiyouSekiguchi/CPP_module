#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "easyfind.hpp"

int	main( void )
{
	std::cout << "############## VECTOR PART ###############" << std::endl;
	std::vector<int>	intVec;
	test_easyfind( intVec );

	std::cout << "\n############## LIST PART #################" << std::endl;
	std::list<int>	intList;
	test_easyfind( intList );

	std::cout << "\n############## DEQUE PART ################" << std::endl;
	std::deque<int>	intDeque;
	test_easyfind( intDeque );

	std::cout << "\n############## SET PART ##################" << std::endl;
	std::set<int>	intSet;
	test_easyfind_2( intSet );

	std::cout << "\n############## MULTISET PART #############" << std::endl;
	std::multiset<int>	intMultiSet;
	test_easyfind_2( intMultiSet );

	std::cout << "\n############## MAP PART ##################" << std::endl;
	std::map<int ,int>	intMap;
	test_easyfind( intMap );

	//VECTOR (STRING) compile error
	/*
	std::vector<std::string>	str_vector;

	str_vector.push_back( "42tokyo" );
	str_vector.push_back( "Born2cord" );
	str_vector.push_back( "tsekiguc" );

	std::cout << "[ str_vector ]" << std::endl;
	for ( size_t i = 0; i < SIZE; ++i )
	{
		if ( i != SIZE - 1 )
			std::cout << str_vector.at( i ) << ", ";
		else
			std::cout << str_vector.at( i ) << std::endl;
	}

	std::cout << "[ RESULT ]" << std::endl;
	try
	{
		std::cout << *(easyfind( str_vector, "42tokyo" )) << std::endl;
		std::cout << *(easyfind( str_vector, "notfound" )) << std::endl;
	}
	catch ( const char * msg )
	{
		std::cerr << msg << std::endl;
	}
	*/

	return ( 0 );
}
