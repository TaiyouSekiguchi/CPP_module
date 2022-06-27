#include "Form.hpp"

Form::Form( void )
	: name( "" )
	, sign( false )
	, signGrade( 150 )
	, execGrade( 150 )
{
	std::cout << "Form Default Constructor called" << std::endl;

	return ;
}

Form::Form( std::string name, int signGrade, int execGrade )
	: name( name )
	, sign( false )
	, signGrade( gradeCheck( signGrade ) )
	, execGrade( gradeCheck( execGrade ) )
{
	std::cout << "Form Parametric Constructor called" << std::endl;

	return ;
}

Form::Form( Form const & src )
	: name( src.getName() )
	, sign( false )
	, signGrade( src.getSignGrade() )
	, execGrade( src.getExecGrade() )
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Form::~Form( void )
{
	std::cout << "Form Destructor called" << std::endl;

	return ;
}

Form &	Form::operator=( Form const & rhs )
{
	std::cout << "Form Assignment operator called" << std::endl;

	if ( this != &rhs )
		this->sign = rhs.getSign();

	return *this;
}

const std::string	Form::getName( void ) const
{
	return ( this->name );
}

bool	Form::getSign( void ) const
{
	return ( this->sign );
}

int		Form::getSignGrade( void ) const
{
	return ( this->signGrade );
}

int		Form::getExecGrade( void ) const
{
	return ( this->execGrade );
}

void	Form::beSigned( Bureaucrat const & b )
{
	if ( this->signGrade < b.getGrade() )
		throw ( Form::GradeTooLowException() );
	this->sign = true;

	return ;
}

void	Form::execute( Bureaucrat const & b ) const 
{
	if ( this->sign == false )
		throw ( Form::NotSignedException() );
	if ( this->execGrade < b.getGrade() )
		throw ( Form::GradeTooLowException() );

	this->action();

	return ;
}

std::ostream &		operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", sign [ " << i.getSign() << " ], signGrade [ " << i.getSignGrade() << " ], execGrade [ " << i.getExecGrade() << " ] .";

	return o;
}

int		gradeCheck( int grade )
{
	if ( grade < 1 )
		throw ( Form::GradeTooHighException() );
	else if ( grade > 150 )
		throw ( Form::GradeTooLowException() );
	return ( grade );
}
