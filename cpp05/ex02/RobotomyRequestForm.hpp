#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		std::string		getTarget( void ) const;
		virtual void	action( void ) const ;

	private:

		std::string		target;

};

//std::ostream &		operator<<( std::ostream & o, RobotomyRequestForm const & i);

#endif
