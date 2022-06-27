#include "Base.hpp"

int main( void )
{
	std::srand( time( NULL ) );

	Base*	tmp = generate();

	identify( tmp );
	identify( *tmp );

	delete tmp;

	return ( 0 );
}
