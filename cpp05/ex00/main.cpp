#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	managerA( "Bob", 20 );
	Bureaucrat	managerB( "Ronald", 50 );
	Bureaucrat	partnerA( "Steph", 120 );
	Bureaucrat	partnerB( partnerA );
	Bureaucrat	etcA( "A", 150 );
	Bureaucrat	etcB( "B", -42 );
	Bureaucrat	etcC( "C", 200 );

	managerB = managerA;

	std::cout << ceo << std::endl;
	std::cout << managerA << std::endl;
	std::cout << managerB << std::endl;
	std::cout << partnerA << std::endl;
	std::cout << partnerB << std::endl;
	std::cout << etcA << std::endl;
	std::cout << etcB << std::endl;
	std::cout << etcC << std::endl;

	return ( 0 );
}
