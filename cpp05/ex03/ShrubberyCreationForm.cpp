#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form( "ShrubberyCreationForm", 145, 137 )
	, target( "John" )
{
	std::cout << "SCF Default Constructor called" << std::endl;

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: Form( "ShrubberyCreationForm", 145, 137 )
	, target( target )
{
	std::cout << "SCF Parametric Constructor called" << std::endl;

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
	: Form( "ShrubberyCreationForm", 145, 137 )
{
	std::cout << "SCF Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "SCF Destructor called" << std::endl;

	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "SCF Assignment operator called" << std::endl;
	Form::operator=(rhs);

	if ( this != &rhs )
		this->target = rhs.getTarget();

	return *this;
}

std::string		ShrubberyCreationForm::getTarget( void ) const
{
	return ( this->target );
}

void	ShrubberyCreationForm::action( void ) const
{
	std::string fname( this->target );
	fname += "_shrubbery";

	std::ofstream ofs( fname );
	if ( !ofs )
	{
		std::cerr << "File open failed." << std::endl;
		std::exit( 1 );
	}

	ofs << "      .     .  .      +     .      .          .             " << std::endl;
	ofs << "     .       .      .     #       .           .             " << std::endl;
	ofs << "        .      .         ###            .      .      .     " << std::endl;
	ofs << "      .      .   *#:. .:##*##:. .:#*  .      .              " << std::endl;
	ofs << "          .      . *####*###*####*  .                       " << std::endl;
	ofs << "       .     *#:.    .:#*###*#:.    .:#*  .        .       ." << std::endl;
	ofs << "  .             *#########*#########*        .        .     " << std::endl;
	ofs << "        .    *#:.  *####*###*####*  .:#*   .       .        " << std::endl;
	ofs << "     .     .  *#######**##*##**#######*                  .  " << std::endl;
	ofs << "                .*##*#####*#####*##*           .      .     " << std::endl;
	ofs << "    .   *#:. ...  .:##*###*###*##:.  ... .:#*     .         " << std::endl;
	ofs << "      .     *#######*##*#####*##*#######*      .     .      " << std::endl;
	ofs << "    .    .     *#####**#######**#####*    .      .          " << std::endl;
	ofs << "            .     *      000      *    .     .              " << std::endl;
	ofs << "       .         .   .   000    .        .       .          " << std::endl;
	ofs << ".. .. ..................O000O........................ ......" << std::endl;

	return ;
}

/*
std::ostream &		operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << i.getTarget();

	return o;
}
*/
