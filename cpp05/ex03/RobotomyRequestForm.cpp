#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form( "RobotomyRequestForm", 72, 45 )
	, target( "John" )
{
	std::cout << "RRF Default Constructor called" << std::endl;
	std::srand( std::time( NULL ) );

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: Form( "RobotomyRequestForm", 72, 45 )
	, target( target )
{
	std::cout << "RRF Parametric Constructor called" << std::endl;
	std::srand( std::time( NULL ) );

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
	: Form( "RobotomyRequestForm", 72, 45 )
{
	std::cout << "RRF Copy Constructor called" << std::endl;
	std::srand( std::time( NULL ) );
	*this = src;

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RRF Destructor called" << std::endl;

	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "RRF Assignment operator called" << std::endl;
	Form::operator=(rhs);

	if ( this != &rhs )
		this->target = rhs.getTarget();

	return *this;
}

std::string		RobotomyRequestForm::getTarget( void ) const
{
	return ( this->target );
}

void	RobotomyRequestForm::action( void ) const
{
	std::cout << "Robotomy START." << std::endl;
	std::cout << "Gagagagagagagaga!!" << std::endl;

	int	num = std::rand() % 2;
	if ( num )
		std::cout << this->target << " Robotomy SUCCESS!!" << std::endl;
	else
		std::cout << this->target << " Robotomy FAIL!!" << std::endl;

	return ;
}

/*
std::ostream &		operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << i.getTarget();

	return o;
}
*/
