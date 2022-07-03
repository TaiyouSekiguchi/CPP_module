#include "iter.hpp"

#define ARRAY_SIZE 3

void	toUpper( char& c )
{
	if ( c >= 'a' && c <= 'z' )
		c -= 'a' - 'A';

	return ;
}

int	main( void )
{
	char		c[ARRAY_SIZE] = { 'a', 'b', 'c' };
	int			i_num[ARRAY_SIZE] = { 1, 2, 3 };
	float		f_num[ARRAY_SIZE] = { 1.0f, 2.0f, 3.0f };
	std::string	str[ARRAY_SIZE] = { "one", "two", "three" };

	std::cout << "<<< BEFORE ARRAY TYPE CHAR >>>" << std::endl;
	::iter( c, ARRAY_SIZE, put);
	std::cout << "<<< AFTER  ARRAY TYPE CHAR >>>" << std::endl;
	::iter( c, ARRAY_SIZE, toUpper);
	::iter( c, ARRAY_SIZE, put);

	std::cout << "\n<<< BEFORE ARRAY TYPE INT >>>" << std::endl;
	::iter( i_num, ARRAY_SIZE, put);
	std::cout << "<<< AFTER  ARRAY TYPE INT >>>" << std::endl;
	::iter( i_num, ARRAY_SIZE, add_one);
	::iter( i_num, ARRAY_SIZE, put);

	std::cout << "\n<<< BEFORE ARRAY TYPE FLOAT >>>" << std::endl;
	::iter( f_num, ARRAY_SIZE, put);
	std::cout << "<<< AFTER  ARRAY TYPE FLOAT >>>" << std::endl;
	::iter( f_num, ARRAY_SIZE, add_one);
	::iter( f_num, ARRAY_SIZE, put);

	std::cout << "\n<<< BEFORE ARRAY TYPE STRING >>>" << std::endl;
	::iter( str, ARRAY_SIZE, put);
	std::cout << "<<< AFTER  ARRAY TYPE STRING>>>" << std::endl;
	::iter( str, ARRAY_SIZE, add_one);
	::iter( str, ARRAY_SIZE, put);

	return ( 0 );
}
