#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::cout << "############### BUREAUCRAT ##############" << std::endl;
	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	manager( "Bob", 20 );
	Bureaucrat	partner( "Steph", 80 );
	Bureaucrat	etc( "etc", 150 );
	std::cout << "#########################################" << std::endl;

	std::cout << "\n###############    FORM    ##############" << std::endl;
	ShrubberyCreationForm	scf( "home" );
	RobotomyRequestForm		rrf( "Takahashi" );
	PresidentialPardonForm	ppf( "Marvin" );
	PresidentialPardonForm	not_sign_ppf( "sunsun" );
	std::cout << "#########################################" << std::endl;

	std::cout << "\n##############   SIGN    ##############" << std::endl;
	try
	{
		ceo.signForm( scf );
		ceo.signForm( rrf );
		ceo.signForm( ppf );
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#######################################" << std::endl;

	std::cout << "\n##############   EXEC    ##############" << std::endl;
	try
	{
		std::cout << "[ SCF ]" << std::endl;
		manager.executeForm( scf );
		std::cout << std::endl;

		std::cout << "[ RRF ]" << std::endl;
		manager.executeForm( rrf );
		std::cout << std::endl;

		std::cout << "[ PPF ]" << std::endl;
		manager.executeForm( ppf );
		std::cout << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "[ PPF ]" << std::endl;
		ceo.executeForm( ppf );
		std::cout << std::endl;

		std::cout << "[ PPF ]" << std::endl;
		ceo.executeForm( not_sign_ppf );
		std::cout << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#######################################" << std::endl;

	return ( 0 );
}
