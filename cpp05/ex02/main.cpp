#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::srand( time( NULL ) );

	Bureaucrat	ceo( "Musk", 1 );
	std::cout << std::endl;

	ShrubberyCreationForm	scf( "home" );

	ceo.signForm( scf );

	ceo.executeForm( scf );


	return (0);



	
	/*
	std::srand( time( NULL ) );

	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	manager( "Bob", 20 );
	Bureaucrat	partner( "Steph", 80 );
	Bureaucrat	etc( "etc", 150 );

	RobotomyRequestForm		rrf( "Takahashi" );

	etc.signForm( rrf );
	manager.signForm( rrf );

	std::cout << rrf << std::endl;

	partner.executeForm( rrf );
	ceo.executeForm( rrf );
	*/

	/*
	Bureaucrat	ceo( "Musk", 1 );
	Bureaucrat	manager( "Bob", 20 );
	Bureaucrat	partner( "Steph", 80 );
	Bureaucrat	etc( "A", 150 );

	std::cout << std::endl;

	Form		high( "High", 1, 1 );
	Form		middle( "Middle", 100, 100 );
	Form		low( "Low", 150, 150 );

	std::cout << std::endl;

	std:: cout << high << std::endl;
	std:: cout << middle << std::endl;
	std:: cout << low << std::endl;

	std::cout << std::endl;

	ceo.executeForm( high );
	manager.signForm( high );
	ceo.signForm( high );
	manager.executeForm( high );
	ceo.executeForm( high );

	return ( 0 );
	*/
}
