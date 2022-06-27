#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "########## BUREAUCRAT ##########" << std::endl;
	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	manager( "Bob", 20 );
	Bureaucrat	partner( "Steph", 80 );
	Bureaucrat	etc( "etc", 150 );
	std::cout << "################################" << std::endl;

	std::cout << "\n########## FORM SUCCESS ##########" << std::endl;

	try
	{
		Form	high( "High", 1, 1 );
		Form	middle( "Middle", 100, 100 );
		Form	low( "Low", 150, 150 );

		std:: cout << high << std::endl;
		ceo.signForm( high );
		std:: cout << high << "\n" << std::endl;

		std:: cout << middle << std::endl;
		manager.signForm( middle );
		std:: cout << middle << "\n" << std::endl;

		std:: cout << low << std::endl;
		etc.signForm( low );
		std:: cout << low << "\n" << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "##################################" << std::endl;

	std::cout << "\n######## FORM EXCEPTION #########" << std::endl;

	try
	{
		Form	tooHigh( "TooHigh", -42, -42 );
	}
	catch ( std::exception & e )
	{
		std::cerr << "Form tooHigh " << e.what() << "\n" << std::endl;
	}

	try
	{
		Form	tooLow( "TooLow", 200, 200 );
	}
	catch ( std::exception & e )
	{
		std::cerr << "Form tooLow " << e.what() << "\n" << std::endl;
	}

	try
	{
		Form	middle( "Middle", 100, 100 );

		std:: cout << middle << std::endl;
		etc.signForm( middle );
		std:: cout << middle << std::endl;

	}
	catch ( std::exception & e )
	{
		std::cerr << "etc " << e.what() << "\n" << std::endl;
	}
	std::cout << "#################################" << std::endl;


	return ( 0 );
}
