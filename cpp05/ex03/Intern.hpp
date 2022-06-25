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

		Form *		makeForm( std::string formName, std::string target);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ( "Grade is TOO HIGH !!" );
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ( "Grade is TOO LOW !!" );
				}
		};

	private:

		int		getIndex( std::string & formName );
		Form *	newForm( std::string target, int index );

};

#endif
