#include "Array.hpp"

int main( void )
{
	Array<int>	i_array( 10 );

	std::cout << "i_array" << std::endl;
	i_array[0] = 3;
	i_array[1] = 42;
	i_array[2] = 55;
	i_array[3] = 1234;
	i_array[4] = 4556;
	i_array[5] = -4242;
	i_array[6] = 8732;
	i_array[7] = 2147483647;
	i_array[8] = 333333;
	i_array[9] = 1031;

	for ( size_t i = 0; i < 10; i++ )
		std::cout << i + 1 << " : " << i_array[i] << std::endl;

	const Array<int>	i_array_copy( i_array );

	i_array[0] = 331031;

	std::cout << "i_array" << std::endl;
	for ( size_t i = 0; i < 10; i++ )
		std::cout << i + 1 << " : " << i_array[i] << std::endl;

	std::cout << "i_array_COPY" << std::endl;
	for ( size_t i = 0; i < 10; i++ )
		std::cout << i + 1 << " : " << i_array_copy[i] << std::endl;

	try
	{
		i_array[-42] = 0;
	}
	catch ( std::exception & e)
	{
		std::cerr << "i_array[-42] throw " << e.what() << std::endl;
	}

	try
	{
		i_array[10] = 0;
	}
	catch ( std::exception & e)
	{
		std::cerr << "i_array[10] throw " << e.what() << std::endl;
	}

	//Error
	//i_array_copy[0] = 331031;

	return ( 0 );
}
