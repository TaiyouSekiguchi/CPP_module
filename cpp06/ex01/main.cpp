#include "Data.hpp"

int main( void )
{
	Data		data;
	uintptr_t	ui_pointer;
	Data*		data_pointer;

	ui_pointer = serialize( &data );
	data_pointer = deserialize( ui_pointer );

	std::cout << "&data        : " << &data << std::endl;
	std::cout << "data_pointer : " << data_pointer << std::endl;
	
	if ( &data == data_pointer )
	{
		std::cout << "Address is match!!" << std::endl;
		std::cout << *data_pointer << std::endl;
	}
	else
		std::cout << "Address is different!!" << std::endl;

	return ( 0 );
}
