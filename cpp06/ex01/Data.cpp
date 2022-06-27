#include "Data.hpp"

Data::Data( void )
	: number(33)
	, name("tsekiguc")
	, weight(60)
	, height(170)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Data::Data( int number, std::string name, int weight, int height )
	: number(number)
	, name(name)
	, weight(weight)
	, height(height)
{
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Data::Data( Data const & src )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Data::~Data( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Data &	Data::operator=( Data const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->number = rhs.getNumber();
		this->name = rhs.getName();
		this->weight = rhs.getWeight();
		this->height = rhs.getHeight();
	}

	return *this;
}

int		Data::getNumber( void ) const
{
	return ( this->number );
}

std::string		Data::getName( void ) const
{
	return ( this->name );
}

int		Data::getWeight( void ) const
{
	return ( this->weight );
}

int		Data::getHeight( void ) const
{
	return ( this->height );
}

std::ostream &		operator<<( std::ostream & o, Data const & i )
{
	o << "number : " << i.getNumber() << "\n";
	o << "name   : " << i.getName() << "\n";
	o << "weight : " << i.getWeight() << "\n";
	o << "height : " << i.getHeight();

	return o;
}

uintptr_t	serialize( Data* ptr )
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		deserialize( uintptr_t raw )
{
	return ( reinterpret_cast<Data*>(raw) );
}
