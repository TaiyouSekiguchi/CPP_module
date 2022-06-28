#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form( void );
		Form( std::string name, int signGrade, int execGrade );
		Form( Form const & src );
		~Form( void );

		Form &	operator=( Form const & rhs );

		const std::string	getName( void ) const;
		bool				getSign( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( Bureaucrat const & b );

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
		bool				sign;
		const int			signGrade;
		const int			execGrade;

};

std::ostream &		operator<<( std::ostream & o, Form const & i);
int					gradeCheck( int grade );

#endif
