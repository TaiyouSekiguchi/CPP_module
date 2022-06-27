#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

std::ostream &	operator<<( std::ostream & o, Base const & i );

Base *	generate( void );
void	identify( Base* p );
void	identify( Base& p );

#endif
