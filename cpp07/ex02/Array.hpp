#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template < typename T >
class Array
{

	public:

		Array( void );
		Array( unsigned int n );
		Array( Array const & src );
		~Array( void );

		Array &		operator=( Array const & rhs );
		T &			operator[]( int i );
		T const &	operator[]( int i ) const;

		unsigned int	size( void ) const;

	private:

		T*				array;
		unsigned int	arraySize;
};

#include "Array.tpp"

#endif
