#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
	: name( "" ), grade( 150 )
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade )
	: name( name )
{
	std::cout << "Bureaucrat Parametric Constructor called" << std::endl;
	if ( grade < 1 )
		throw ( Bureaucrat::GradeTooHighException() );
	else if ( grade > 150 )
		throw ( Bureaucrat::GradeTooLowException() );
	this->grade = grade;

	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
	: name( src.getName() )
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called" << std::endl;

	return ;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if ( this != &rhs )
		this->grade = rhs.getGrade();

	return *this;
}

const std::string	Bureaucrat::getName( void ) const
{
	return ( this->name );
}

int		Bureaucrat::getGrade( void ) const
{
	return ( this->grade );
}

void	Bureaucrat::increment( void )
{
	if ( this->grade - 1 < 1 )
		throw ( Bureaucrat::GradeTooHighException() );
	std::cout << this->name << " UPGRADE !! ;)" << std::endl;
	this->grade -= 1;
}

void	Bureaucrat::decrement( void )
{
	if ( this->grade + 1 > 150 )
		throw ( Bureaucrat::GradeTooLowException() );
	std::cout << this->name << " DOWNGRADE !! :(" << std::endl;
	this->grade += 1;
}

void	Bureaucrat::signForm( Form & f ) const
{
	try
	{
		f.beSigned( *this );
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( Form const & form )
{
	try
	{
		form.execute( *this );
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";

	return o;
}
