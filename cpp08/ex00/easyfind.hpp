#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

template< typename T >
typename T::const_iterator	easyfind( const T& ocean, int dia )
{
	typename T::const_iterator	ret = std::find( ocean.begin(), ocean.end(), dia );
	if ( ret == ocean.end() )
		throw ( "easyfind clould not find." );

	return ( ret );
}

template<>
std::map<int, int>::const_iterator	easyfind<std::map<int, int> >( const std::map<int, int> & ocean, int dia )
{
	std::map<int, int>::const_iterator	ret = ocean.find( dia );
	if ( ret == ocean.end() )
		throw ( "easyfind clould not find." );

	return ( ret );
}

template< typename T >
void	test_easyfind( T& container )
{
	container.push_back( 0 );
	container.push_back( 42 );
	container.push_back( 33 );
	container.push_back( 9999 );
	container.push_back( -522 );

	std::cout << "[ CONTAINER ]" << std::endl;
	typename T::const_iterator	it = container.begin();
	typename T::const_iterator	itEnd = container.end();
	for ( ; it != itEnd; ++it )
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "[ SEARCH ]" << std::endl;
	std::cout << "42, 1031" << std::endl;

	std::cout << "[ RESULT ]" << std::endl;
	try
	{
		std::cout << *(easyfind( container, 42 )) << " is FOUND !!" << std::endl;
		std::cout << *(easyfind( container, 1031 )) << " is FOUND !!" << std::endl;
	}
	catch ( const char * msg )
	{
		std::cerr << msg << std::endl;
	}
}

template< typename T >
void	test_easyfind_2( T & container )
{
	const int a[] = { 0, 42, 33, 9999, -522 };

	T	tmp(a, a + 5);

	container = tmp;

	std::cout << "[ CONTAINER ]" << std::endl;
	typename T::const_iterator	it = container.begin();
	typename T::const_iterator	itEnd = container.end();
	for ( ; it != itEnd; ++it )
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "[ SEARCH ]" << std::endl;
	std::cout << "42, 1031" << std::endl;

	std::cout << "[ RESULT ]" << std::endl;
	try
	{
		std::cout << *(easyfind( container, 42 )) << " is FOUNT !!" << std::endl;
		std::cout << *(easyfind( container, 1031 )) << " is FOUNT !!" << std::endl;
	}
	catch ( const char * msg )
	{
		std::cerr << msg << std::endl;
	}
}

template<>
void	test_easyfind<std::map<int, int> >( std::map<int, int> & container )
{
	const std::pair<int, int> a[] = {
		std::make_pair( 0, 0 ),
		std::make_pair( 42, 1 ),
		std::make_pair( 33, 2 ),
		std::make_pair( 9999, 3 ),
		std::make_pair( -522, 4 ),
	};

	std::map<int, int>	tmp(a, a + 5);

	container = tmp;

	std::cout << "[ CONTAINER ]" << std::endl;
	std::map<int, int>::const_iterator	it = container.begin();
	std::map<int, int>::const_iterator	itEnd = container.end();
	for ( ; it != itEnd; ++it )
		std::cout << "[ " <<  it->first << " : " << it->second << " ]  ";
	std::cout << std::endl;

	std::cout << "[ SEARCH ]" << std::endl;
	std::cout << "42, 1031" << std::endl;

	std::cout << "[ RESULT ]" << std::endl;
	try
	{
		std::cout << easyfind( container, 42 )->second << " is FOUND !!" << std::endl;
		std::cout << easyfind( container, 1031 )->second << " is FOUND !!" << std::endl;
	}
	catch ( const char * msg )
	{
		std::cerr << msg << std::endl;
	}
}

#endif
