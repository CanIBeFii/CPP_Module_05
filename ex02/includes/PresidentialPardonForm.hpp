#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
		// Constructors
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& copy );

		// Destructors
		virtual ~PresidentialPardonForm( void );

		// Operators
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& copy );

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