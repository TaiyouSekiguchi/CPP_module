#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	manager( "Bob", 20 );
	Bureaucrat	partner( "Steph", 80 );
	Bureaucrat	etc( "A", 150 );

	Form		high1( "High", 1, 1 );
	Form		high2( "High", 1, 1 );
	Form		middle( "Middle", 100, 100 );
	Form		low( "Low", 150, 150 );
	Form		tooHigh( "TooHigh", -42, -42 );
	Form		tooLow( "TooLow", 200, 200 );

	std:: cout << high1 << std::endl;
	std:: cout << middle << std::endl;
	std:: cout << low << std::endl;
	std:: cout << tooHigh << std::endl;
	std:: cout << tooLow << std::endl;

	//Error ( copy is forbbiden )
	//Form		middleCopy( middle );
	//middle = high;

	ceo.signForm( high1 );
	std:: cout << high1 << std::endl;

	manager.signForm( high2 );
	std:: cout << high2 << std::endl;

	manager.signForm( middle );
	std:: cout << middle << std::endl;

	return ( 0 );
}
