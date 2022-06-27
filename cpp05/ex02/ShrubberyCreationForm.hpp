#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <cstdlib>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		std::string		getTarget( void ) const;
		virtual void	action( void ) const ;

	private:

		std::string		target;

};

//std::ostream &		operator<<( std::ostream & o, ShrubberyCreationForm const & i);

#endif
