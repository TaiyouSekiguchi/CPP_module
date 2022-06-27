#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "############ SUCCESS PART ###########" << std::endl;

	try
	{
		Bureaucrat	ceo( "Musk", 1 );
		Bureaucrat	managerA( "Bob", 20 );
		Bureaucrat	managerB( "Ronald", 50 );

		std::cout << ceo << std::endl;

		std::cout << managerA << std::endl;
		managerA.increment();
		std::cout << managerA << std::endl;

		std::cout << managerB << std::endl;
		managerB.decrement();
		std::cout << managerB << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "#####################################" << std::endl;

	std::cout << "\n############ EXCEPTION PART #########" << std::endl;

	try
	{
		Bureaucrat	etcA( "A", -42);
	}
	catch ( std::exception& e )
	{
		std::cerr << "etcA " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	etcB( "B", 200 );
	}
	catch ( std::exception& e )
	{
		std::cerr << "etcB " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	etcC( "C", 1 );
		etcC.increment();
	}
	catch ( std::exception& e )
	{
		std::cerr << "etcC " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	etcD( "D", 150 );
		etcD.decrement();
	}
	catch ( std::exception& e )
	{
		std::cerr << "etcD " << e.what() << std::endl;
	}

	std::cout << "#####################################" << std::endl;

	return ( 0 );
}
