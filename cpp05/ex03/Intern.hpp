#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{

	public:

		Intern( void );
		Intern( Intern const & src );
		~Intern( void );

		Intern & operator=( Intern const & rhs );

		Form *	makeForm( const std::string formName, const std::string target);

};

#endif
