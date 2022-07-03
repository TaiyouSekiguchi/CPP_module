#ifndef ARRAY_TPP
# define ARRAY_TPP

template < typename T >
Array<T>::Array( void )
	: array( new T[0] )
	, arraySize( 0 )
{
	std::cout << "Array default constructor called." << std::endl;

	return ;
}

template < typename T >
Array<T>::Array( unsigned int n )
	: array( new T[n] )
	, arraySize( n )
{
	std::cout << "Array parametric constructor called." << std::endl;
	
	return ;
}

template < typename T >
Array<T>::Array( Array const & src )
	: array( new T[0] )
	, arraySize( 0 )
{
	std::cout << "Array copy Constructor called" << std::endl;
	*this = src;

	return ;
}

template < typename T >
Array<T>::~Array( void )
{
	std::cout << "Array destructor called." << std::endl;

	delete [] array;
}

template < typename T >
Array<T> &	Array<T>::operator=( Array const & rhs )
{
	std::cout << "Array assignment operator called" << std::endl;

	if ( this != &rhs )
	{
		this->arraySize = rhs.size();

		T*	tmp = new T[this->arraySize];

		for ( size_t i = 0; i < this->arraySize; i++ )
			tmp[i] = rhs.array[i];

		delete [] this->array;

		this->array = tmp;
	}

	return *this;
}

template < typename T >
T&	Array<T>::operator[]( int i )
{
	if ( i < 0 || static_cast<unsigned int >(i) >= this->arraySize )
		throw std::out_of_range("Access to out of range.");

	return ( this->array[i] );
}

template < typename T >
T const &	Array<T>::operator[]( int i ) const
{
	if ( i < 0 || static_cast<unsigned int>(i) >= this->arraySize )
		throw std::out_of_range("Access to out of range.");

	return ( this->array[i] );
}

template < typename T >
unsigned int	Array<T>::size( void ) const
{
	return ( this->arraySize );
}

#endif
