#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm( void );

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

		std::string		getTarget( void ) const;
		virtual void	action( void ) const ;

	private:

		std::string		target;

};

//std::ostream &		operator<<( std::ostream & o, PresidentialPardonForm const & i);

#endif
