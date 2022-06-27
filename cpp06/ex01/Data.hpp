#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>


class Data
{

	public:

		Data();
		Data( int number, std::string name, int weight, int height );
		Data( Data const & src );
		~Data();

		Data & operator=( Data const & rhs );

		int				getNumber( void ) const;
		std::string		getName( void ) const;
		int				getWeight( void ) const;
		int				getHeight( void ) const;

	private:

		int				number;
		std::string		name;
		int				weight;
		int				height;
};

std::ostream &	operator<<( std::ostream & o, Data const & i );

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
