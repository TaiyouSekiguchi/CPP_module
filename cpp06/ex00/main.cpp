#include "Converter.hpp"

int	main( int argc, char *argv[] )
{
	if ( argc != 2 )
	{
		std::cerr << "Error\nUsage : ./Converter parameter" << std::endl;
		return ( 1 );
	}

	std::string	str = std::string(argv[1]);
	Converter	converter( str );

	try
	{
		converter.detectType();
		converter.convertActualType();
		converter.convertExplicitly();
		converter.displayResult();
	}
	catch ( const char* errorMessage )
	{
		std::cerr << errorMessage << std::endl;
		return ( 1 );
	}

	return ( 0 );
}
