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

static Form* newShrubberyCreationForm( const std::string& target )
{ return ( new ShrubberyCreationForm( target ) ); }

static Form* newRobotomyRequestForm( const std::string& target )
{ return ( new RobotomyRequestForm( target ) ); }

static Form* newPresidentialPardonForm( const std::string& target )
{ return ( new PresidentialPardonForm( target ) ); }

Form *	Intern::makeForm( const std::string formName, const std::string target )
{
	const std::string	forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon" };

	Form *	(* const newForms[3])(const std::string& target) = {
		newShrubberyCreationForm,
		newRobotomyRequestForm,
		newPresidentialPardonForm };

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (newForms[i](target));
		}
	}
	std::cerr << "Error\nInvalid form name." << std::endl;
	return ( NULL );
}
