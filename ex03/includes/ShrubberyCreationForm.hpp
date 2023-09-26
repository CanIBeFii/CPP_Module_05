#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		// Constructors
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );

		// Destructors
		virtual ~ShrubberyCreationForm( void );

		// Operators
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& copy );

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