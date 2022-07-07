#include "Span.hpp"

Span::Span( void )
	: sizeMax( 0 )
{
	//std::cout << "Span default Constructor called" << std::endl;
	return ;
}

Span::Span( unsigned int n )
	: sizeMax( n )
{
	std::srand( time( NULL ) );
	//std::cout << "Span parametric Constructor called" << std::endl;
	return ;
}

Span::Span( Span const & src )
{
	//std::cout << "Span copy Constructor called" << std::endl;
	std::srand( time( NULL ) );
	*this = src;
	return ;
}

Span::~Span( void )
{
	//std::cout << "Span destructor called" << std::endl;
	return ;
}

Span &	Span::operator=( Span const & rhs )
{
	//std::cout << "Span assignment operator called" << std::endl;

	if ( this != &rhs )
	{
		this->intMultiSet = rhs.intMultiSet;
		this->sizeMax = rhs.getSizeMax();
	}

	return *this;
}

unsigned int	Span::getSizeMax( void ) const
{
	return this->sizeMax;
}

void	Span::addNumber( int addNum )
{
	if ( this->intMultiSet.size() >= this->sizeMax )
		throw ( "Multiset size over !!" );

	this->intMultiSet.insert( addNum );

	return ;
}

unsigned int	Span::shortestSpan( void ) const
{
	unsigned int	retSpan;

	if ( this->intMultiSet.empty()
		|| this->intMultiSet.size() == 1)
		throw ( "shortestSpan Error\nThe element is empty or has only one element." );

	unsigned int					prev;
	std::multiset<int>::iterator	it;

	retSpan = UINT_MAX;
	it = this->intMultiSet.begin();
	prev = *it;
	++it;
	while ( it != this->intMultiSet.end() )
	{
		if ( *it - prev < retSpan )
			retSpan = *it - prev;
		prev = *it;
		++it;
	}

	return ( retSpan );
}

unsigned int	Span::longestSpan( void ) const
{
	unsigned int	retSpan;

	if ( this->intMultiSet.empty()
		|| this->intMultiSet.size() == 1)
		throw ( "longestSpan Error\nThe element is empty or has only one element." );

	std::multiset<int>::iterator			it;
	std::multiset<int>::reverse_iterator	itEnd;

	it = this->intMultiSet.begin();
	itEnd = this->intMultiSet.rbegin();
	retSpan = *itEnd - *it;

	return ( retSpan );
}

void	Span::setRandomNumber( unsigned int setSize )
{
	if ( this->sizeMax < setSize )
		throw ( "setRandomNumber Error\nsetSize too big." );

	this->intMultiSet.clear();

	int		array[setSize];

	std::cout << "RAND_MAX : " << RAND_MAX << std::endl;
	for ( size_t i = 0; i < setSize; ++i )
	{
		int	num = std::rand() % INT_MAX;
		array[i] = num;
	}

	std::multiset<int>	tmp( array, array + setSize );
	this->intMultiSet = tmp;

	std::cout << "setRandomNumber SUCCESS!!" << std::endl;

	return ;
}
