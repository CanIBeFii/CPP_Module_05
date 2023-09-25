#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		// Constructors
		Form( void );
		Form( const std::string& name, int signerGrade, int executeGrade );
		Form( const Form& copy );

		// Destructor
		~Form( void );

		// Operators
		Form&	operator=( const Form& copy );

		// Functions
		// Getters
		const std::string&	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignerGrade( void ) const;
		int					getExecuteGrade( void ) const;

		void				beSigned( Bureaucrat& b );

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signerGrade;
		const int			_executeGrade;
};

std::ostream&	operator<<( std::ostream& out, const Form& f );

#endif