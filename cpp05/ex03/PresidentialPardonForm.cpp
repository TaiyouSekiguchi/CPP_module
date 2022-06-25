#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form( "PresidentialPardonForm", 25, 5 )
	, target( "John" )
{
	std::cout << "PPF Default Constructor called" << std::endl;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: Form( "PresidentialPardonForm", 25, 5 )
	, target( target )
{
	std::cout << "PPF Parametric Constructor called" << std::endl;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
	: Form( "PresidentialPardonForm", 25, 5 )
{
	std::cout << "PPF Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PPF Destructor called" << std::endl;

	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "PPF Assignment operator called" << std::endl;
	Form::operator=(rhs);

	if ( this != &rhs )
		this->target = rhs.getTarget();

	return *this;
}

std::string		PresidentialPardonForm::getTarget( void ) const
{
	return ( this->target );
}

void	PresidentialPardonForm::action( void ) const
{
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox!!" << std::endl;
}

/*
std::ostream &		operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << i.getTarget();

	return o;
}
*/
