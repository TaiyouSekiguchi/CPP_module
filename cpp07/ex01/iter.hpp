#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <iomanip>

template< typename T >
void	iter( T* array, size_t size, void (*f)(T&) )
{
	if ( array == NULL || f == NULL )
		return ;
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}

	return ;
}

template< typename T >
void	iter(const T* array, size_t size, void (*f)(const T&) )
{
	if ( array == NULL || f == NULL )
		return ;
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}

	return ;
}

template< typename T >
void	add_one( T& tmp )
{
	tmp += 1;
}

template<>
void	add_one<std::string>( std::string& tmp )
{
	tmp += "1";
}

template< typename T >
void	put( T& tmp )
{
	std::cout << tmp << std::endl;

	return ;
}

template<>
void	put<float>(float& tmp )
{
	std::cout << std::fixed << std::setprecision(3) << tmp << "f" << std::endl;

	return ;
}

#endif
