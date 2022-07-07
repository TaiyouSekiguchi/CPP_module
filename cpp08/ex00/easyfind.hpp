#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template< typename T >
typename T::const_iterator	easyfind(const T& ocean, int dia)
{
	typename T::const_iterator	ret = std::find(ocean.begin(), ocean.end(), dia);
	if (ret == ocean.end())
		throw ("easyfind clould not find.");

	return (ret);
}

template< typename T >
typename T::iterator	easyfind(T& ocean, int dia)
{
	typename T::iterator	ret = std::find(ocean.begin(), ocean.end(), dia);
	if (ret == ocean.end())
		throw ("easyfind clould not find.");

	return (ret);
}

#endif
