#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void	TestEasyFindVector(void)
{
	std::cout << "TEST easyfind for vector : ";

	std::vector<int>	container;

	container.push_back( 0 );
	container.push_back( 42 );
	container.push_back( 33 );
	container.push_back( 9999 );
	container.push_back( -522 );

	try
	{
		easyfind(container, 0);
		easyfind(container, 42);
		easyfind(container, 33);
		easyfind(container, 9999);
		easyfind(container, -522);
	}
	catch(const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	try
	{
		easyfind(container, 1031);
		std::cerr << "[ NG ]" << std::endl;
	}
	catch(const char* msg)
	{
		;
	}

	std::cout << "[ OK ]" << std::endl;

	return ;
}

void	TestEasyFindList(void)
{
	std::cout << "TEST easyfind for list : ";

	std::list<int>	container;

	container.push_back( 0 );
	container.push_back( 42 );
	container.push_back( 33 );
	container.push_back( 9999 );
	container.push_back( -522 );

	try
	{
		easyfind(container, 0);
		easyfind(container, 42);
		easyfind(container, 33);
		easyfind(container, 9999);
		easyfind(container, -522);
	}
	catch(const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	try
	{
		easyfind(container, 1031);
		std::cerr << "[ NG ]" << std::endl;
	}
	catch(const char* msg)
	{
		;
	}

	std::cout << "[ OK ]" << std::endl;

	return ;
}

void	TestEasyFindDeque(void)
{
	std::cout << "TEST easyfind for deque : ";

	std::deque<int>	container;

	container.push_back( 0 );
	container.push_back( 42 );
	container.push_back( 33 );
	container.push_back( 9999 );
	container.push_back( -522 );

	try
	{
		easyfind(container, 0);
		easyfind(container, 42);
		easyfind(container, 33);
		easyfind(container, 9999);
		easyfind(container, -522);
	}
	catch(const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	try
	{
		easyfind(container, 1031);
		std::cerr << "[ NG ]" << std::endl;
	}
	catch(const char* msg)
	{
		;
	}

	std::cout << "[ OK ]" << std::endl;

	return ;
}


int	main( void )
{
	TestEasyFindVector();
	TestEasyFindList();
	TestEasyFindDeque();

	return ( 0 );
}
