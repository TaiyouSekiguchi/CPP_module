#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>


class Bureaucrat
{

	public:

		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat( void );

		Bureaucrat & operator=( Bureaucrat const & rhs );

		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				increment( void );
		void				decrement( void );

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

		const std::string	name;
		int					grade;
};

std::ostream &		operator<<( std::ostream & o, Bureaucrat const & i);

#endif
