#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		// Constructors
		AForm( void );
		AForm( const std::string& name, int signerGrade, int executeGrade );
		AForm( const AForm& copy );

		// Destructor
		virtual ~AForm( void );

		// Operators
		AForm&	operator=( const AForm& copy );

		// Functions
		// Getters
		const std::string&	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignerGrade( void ) const;
		int					getExecuteGrade( void ) const;

		virtual void		beSigned( Bureaucrat& b );
		virtual void		execute( const Bureaucrat& executor ) const = 0;

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

std::ostream&	operator<<( std::ostream& out, const AForm& f );

#endif