#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void	swap( T& a, T& b )
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;

	return ;
}

template< typename T>
const T &		min( T const & a, T const & b )
{
	if ( a < b )
		return ( a );
	else
		return ( b );
}

template< typename T>
const T &		max( T const & a, T const & b )
{
	if ( a > b )
		return ( a );
	else
		return ( b );
}

#endif
