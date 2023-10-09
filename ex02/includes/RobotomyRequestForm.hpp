#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	public:
		// Constructors
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& copy );

		// Destructors
		virtual ~RobotomyRequestForm( void );

		// Operators
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& copy );

		// Functions
		//	Getters
		const std::string&		getTarget( void ) const;

		virtual void			execute( const Bureaucrat& executor ) const;

		// Exceptions
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

	private:
		const std::string	_target;
};

#endif