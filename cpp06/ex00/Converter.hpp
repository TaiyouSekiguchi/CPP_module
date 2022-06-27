#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

class Converter
{

	public:

		Converter( void );
		Converter( std::string argv );
		Converter( Converter const & src );
		~Converter( void );

		Converter & operator=( Converter const & rhs );


		void			detectType( void );
		void			convertActualType( void );
		void			convertExplicitly( void );
		void			displayResult( void ) const;

	private:

		typedef enum
		{
			NONE = 0,
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
		}	t_type;

		std::string		param;
		t_type			type;
		char			c;
		int				i_num;
		float			f_num;
		double			d_num;

		std::string		getParam( void ) const;
		t_type			getType( void ) const;
		char			getC( void ) const;
		int				getInum( void ) const;
		float			getFnum( void ) const;
		double			getDnum( void ) const;

		void			displayChar( void ) const;
		void			displayInt( void ) const;
		void			displayFloat( void ) const;
		void			displayDouble( void ) const;

};

#endif
