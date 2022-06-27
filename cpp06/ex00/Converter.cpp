#include "Converter.hpp"

Converter::Converter( void )
{
	//std::cout << "Converter Default Constructor called" << std::endl;

	return ;
}

Converter::Converter( std::string argv )
	: param( argv )
{
	//std::cout << "Converter Parametric Constructor called" << std::endl;

	return ;
}

Converter::Converter( Converter const & src )
{
	//std::cout << "Converter Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Converter::~Converter( void )
{
	//std::cout << "Converter Destructor called" << std::endl;

	return ;
}

Converter &	Converter::operator=( Converter const & rhs )
{
	//std::cout << "Converter Assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->param = rhs.getParam();
		this->type = rhs.getType();
		this->c = rhs.getC();
		this->i_num = rhs.getInum();
		this->f_num = rhs.getFnum();
		this->d_num = rhs.getDnum();
	}

	return *this;
}

std::string		Converter::getParam( void ) const
{
	return ( this->param );
}

Converter::t_type	Converter::getType( void ) const
{
	return ( this->type );
}

char			Converter::getC( void ) const
{
	return ( this->c );
}

int				Converter::getInum( void ) const
{
	return ( this->i_num );
}

float			Converter::getFnum( void ) const
{
	return ( this->f_num );
}

double			Converter::getDnum( void ) const
{
	return ( this->d_num );
}

void	Converter::detectType( void )
{
	if ( this->param == "-inff"
		|| this->param == "+inff"
		|| this->param == "nanf" )
		this->type = FLOAT;
	else if ( this->param == "-inf"
		|| this->param == "+inf"
		|| this->param == "nan" )
		this->type = DOUBLE;
	else if (this->param.length() == 1
		&& !std::isdigit(this->param[0])
		&& isascii(this->param[0]))
		this->type = CHAR;
	else if (std::isdigit(this->param[0])
		|| this->param[0] == '+'
		|| this->param[0] == '-'
		|| this->param[0] == '.')
	{
		size_t	dot_count = 0;

		if (this->param[0] != '.')
			this->type = INT;
		else
		{
			dot_count++;
			this->type = DOUBLE;
		}

		for ( size_t i = 1; i < this->param.length(); i++ )
		{
			if (std::isdigit(this->param[i]))
				;
			else if ( this->param[i] == '.' )
			{
				dot_count++;
				if ( dot_count >= 2 )
					throw "Error\nInvalid argument";
				this->type = DOUBLE;
			}
			else if ( this->param[i] == 'f' )
			{
				if ( dot_count == 0 || i != this->param.length() - 1 )
					throw "Error\nInvalid argument";
				this->type = FLOAT;
			}
			else
				throw "Error\nInvalid argument";
		}
	}
	else
		throw "Error\nInvalid argument";
}

void	Converter::convertActualType( void )
{
	const char *	s_tmp;
	s_tmp = this->param.c_str();

	errno = 0;
	switch ( this->type )
	{
		case CHAR:
			this->c = this->param[0];
			break ;
		case INT:
			long	l_tmp;
			l_tmp = strtol(s_tmp, NULL, 10);
			if (l_tmp > INT_MAX || l_tmp < INT_MIN || errno == ERANGE)
				throw "Error\nINT overflow.";
			this->i_num = l_tmp;
			break ;
		case FLOAT:
			if ( this->param == "-inff" )
				this->f_num = -INFINITY;
			else if ( this->param == "inff" )
				this->f_num = INFINITY;
			else if ( this->param == "nanf" )
				this->f_num = NAN;
			else
				this->f_num = strtof(s_tmp, NULL);
			if ( errno == ERANGE )
				throw "Error\nFLOAT overflow.";
			break ;
		case DOUBLE:
			if ( this->param == "-inf" )
				this->d_num = -INFINITY;
			else if ( this->param == "inf" )
				this->d_num = INFINITY;
			else if ( this->param == "nan" )
				this->d_num = NAN;
			else
				this->d_num = strtod(s_tmp, NULL);
			if ( errno == ERANGE )
				throw "Error\nDOUBLE overflow.";
			break ;
		default:
			throw "Error\nWhat's happened.";
			break ;
	}

	return ;
}

void	Converter::convertExplicitly( void )
{
	if ( this->type == CHAR )
	{
		this->i_num = static_cast<int>(this->c);
		this->f_num = static_cast<float>(this->c);
		this->d_num = static_cast<double>(this->c);
	}
	else if ( this->type == INT )
	{
		this->c = static_cast<char>(this->i_num);
		this->f_num = static_cast<float>(this->i_num);
		this->d_num = static_cast<double>(this->i_num);
	}
	else if ( this->type == FLOAT )
	{
		this->c = static_cast<char>(this->f_num);
		this->i_num = static_cast<int>(this->f_num);
		this->d_num = static_cast<double>(this->f_num);
	}
	else if ( this->type == DOUBLE )
	{
		this->c = static_cast<char>(this->d_num);
		this->i_num = static_cast<int>(this->d_num);
		this->f_num = static_cast<float>(this->d_num);
	}

	return ;
}

void	Converter::displayChar( void ) const
{
	std::cout << "char   : ";

	if ( this->i_num > CHAR_MAX
		|| this->i_num < CHAR_MIN
		|| isnan(this->f_num)
		|| isinf(this->f_num) )
		std::cout << "impossible" << std::endl;
	else if ( std::isprint( this->c ) )
		std::cout << "'" << this->c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	return ;
}

void	Converter::displayInt( void ) const
{
	std::cout << "int    : ";

	if ( this->d_num > static_cast<double>(INT_MAX)
		|| this->d_num < static_cast<double>(INT_MIN)
		|| isnan(this->f_num)
		|| isinf(this->f_num) )
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->i_num << std::endl;

	return ;
}

void	Converter::displayFloat( void ) const
{
	std::cout << "float  : ";

	if ( isinf(this->f_num) && ( this->f_num > -INFINITY ) )
		std::cout << "+" << this->f_num << "f" << std::endl;
	else if ( this->f_num == static_cast<float>(this->i_num)
			&& this->f_num < 1000000.0f )
		std::cout << this->d_num << ".0f" << std::endl;
	else
		std::cout << this->f_num << "f" << std::endl;

	return ;
}

void	Converter::displayDouble( void ) const
{
	std::cout << "double : ";

	if ( isinf(this->d_num) && ( this->d_num > -INFINITY ) )
		std::cout << "+" << this->d_num << std::endl;
	else if ( this->d_num == static_cast<double>(this->i_num)
			&& this->d_num < 1000000.0 )
		std::cout << this->d_num << ".0" << std::endl;
	else
		std::cout << this->d_num << std::endl;

	return ;
}

void	Converter::displayResult( void ) const
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();

	return ;
}
