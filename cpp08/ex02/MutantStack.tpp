#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template < class T, class Container >
MutantStack<T, Container>::MutantStack( void )
{
	//std::cout << "MutantStack default Constructor called" << std::endl;
	return ;
}

template < class T, class Container >
MutantStack<T, Container>::MutantStack( MutantStack const & src )
{
	//std::cout << "MutantStack copy Constructor called" << std::endl;
	*this = src;

	return ;
}

template < class T, class Container >
MutantStack<T, Container>::~MutantStack( void )
{
	//std::cout << "MutantStack destructor called" << std::endl;
	return ;
}

template < class T, class Container >
MutantStack<T, Container> &	MutantStack<T, Container>::operator=( MutantStack const & rhs )
{
	//std::cout << "MutantStack assignment operator called" << std::endl;
	std::stack<T, Container>::operator=(rhs);

	return *this;
}

template < class T, class Container >
typename MutantStack< T, Container >::iterator		MutantStack< T, Container >::begin( void )
{
	return ( this->c.begin() );
}

template < class T, class Container >
typename MutantStack< T, Container >::iterator		MutantStack< T, Container >::end( void )
{
	return ( this->c.end() );
}

template < class T, class Container >
typename MutantStack< T, Container >::reverse_iterator	MutantStack< T, Container >::rbegin( void )
{
	return ( this->c.rbegin() );
}

template < class T, class Container >
typename MutantStack< T, Container >::reverse_iterator	MutantStack< T, Container >::rend( void )
{
	return ( this->c.rend() );
}

template < class T, class Container >
typename MutantStack< T, Container >::const_iterator	MutantStack< T, Container >::begin( void ) const
{
	return ( this->c.begin() );
}

template < class T, class Container >
typename MutantStack< T, Container >::const_iterator	MutantStack< T, Container >::end( void ) const
{
	return ( this->c.end() );
}

template < class T, class Container >
typename MutantStack< T, Container >::const_reverse_iterator	MutantStack< T, Container >::rbegin( void ) const
{
	return ( this->c.rbegin() );
}

template < class T, class Container >
typename MutantStack< T, Container >::const_reverse_iterator	MutantStack< T, Container >::rend( void ) const
{
	return ( this->c.rend() );
}

#endif

