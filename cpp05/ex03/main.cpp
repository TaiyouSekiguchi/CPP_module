#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::srand( time( NULL ) );

	Bureaucrat	ceo( "Musk", 1 );

	Form *	rrf;
	Intern	internA;

	rrf = internA.makeForm( "robotomy request", "yusuke" );

	std::cout << *rrf << std::endl;

	ceo.signForm( *rrf );

	std::cout << *rrf << std::endl;

	ceo.executeForm( *rrf );

	delete rrf;

	return ( 0 );

}
