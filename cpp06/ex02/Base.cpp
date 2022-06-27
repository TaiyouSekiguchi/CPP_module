#include "Base.hpp"

std::ostream &	operator<<( std::ostream & o, Base const & i )
{
	o << "Base class";

	return o;
}

Base *	generate( void )
{
	Base *	ret;
	int		num;

	num = std::rand() % 3;
	switch (num)
	{
		case 0:
			ret = new A();
			break ;
		case 1:
			ret = new B();
			break ;
		case 2:
			ret = new C();
			break ;
		default:
			ret = NULL;
			break ;
	}

	return ( ret );
}

void	identify( Base* p )
{
	std::cout << "p : ";

	A*	a_pointer = dynamic_cast<A*>(p);
	if ( a_pointer != NULL )
	{
		std::cout << "A" << std::endl;
		return ;
	}

	B*	b_pointer = dynamic_cast<B*>(p);
	if ( b_pointer != NULL )
	{
		std::cout << "B" << std::endl;
		return ;
	}

	C*	c_pointer = dynamic_cast<C*>(p);
	if ( c_pointer != NULL )
	{
		std::cout << "C" << std::endl;
		return ;
	}

	return ;
}

void	identify( Base& p )
{
	std::cout << "p : ";
	try
	{
		A&	a_ref = dynamic_cast<A&>(p);
		std::cout << "A" << a_ref << std::endl;
	}
	catch ( std::bad_cast& )
	{
		;
	}

	try
	{
		B&	b_ref = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch ( std::bad_cast& )
	{
		;
	}

	try
	{
		C&	b_ref = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch ( std::bad_cast& )
	{
		;
	}

	return ;
}
