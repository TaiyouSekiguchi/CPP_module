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
		virtual ~Form( void );

		Form &	operator=( Form const & rhs );

		const std::string	getName( void ) const;
		bool				getSign( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		void				beSigned( Bureaucrat const & b );
		void				execute( Bureaucrat const & b ) const;
		virtual void		action( void ) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ( "Form is NOT SIGNED !!" );
				}
		};

	private:

		//Form( Form const & src );
		//Form &	operator=( Form const & rhs );

		const std::string	name;
		bool				sign;
		int			signGrade;
		int			execGrade;

};

std::ostream &		operator<<( std::ostream & o, Form const & i);
int					gradeCheck( int grade );

#endif
