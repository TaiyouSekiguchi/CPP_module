#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern Default Constructor called" << std::endl;

	return ;
}

Intern::Intern( Intern const & src )
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Intern::~Intern( void )
{
	std::cout << "Intern Destructor called" << std::endl;

	return ;
}

Intern &	Intern::operator=( Intern const & rhs )
{
	std::cout << "Intern Assignment operator called" << std::endl;
	if ( this != &rhs )
		;
		//this->grade = rhs.getGrade();

	return *this;
}

std::string forms[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

int		Intern::getIndex( std::string & formName )
{
	int		index = -1;

	for ( int i = 0; i < 3; i++ )
	{
		if ( forms[i] == formName )
		{
			index = i;
			break ;
		}
	}

	return ( index );
}

Form *	Intern::newForm( std::string target, int index )
{
	Form *	retForm;

	switch ( index )
	{
		case 0:
			retForm = new ShrubberyCreationForm( target );
			break ;
		case 1:
			retForm = new RobotomyRequestForm( target );
			break ;
		case 2:
			retForm = new PresidentialPardonForm( target );
			break ;
		default:
			std::cerr << "What's happen!?" << std::endl;
			retForm = NULL;
			break ;
	}

	return ( retForm );
}

Form *	Intern::makeForm( std::string formName, std::string target )
{
	Form *	retForm;
	int		index;

	index = getIndex( formName );
	if ( index == -1 )
	{
		std::cerr << "Error\nInvalid form name." << std::endl;
		return ( NULL );
	}
	retForm = newForm( target, index );
	std::cout << "Intern creates " << formName << std::endl;

	return ( retForm );
}
