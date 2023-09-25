#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"	

class Form;

class Bureaucrat {
	public:
		// Constructor
		Bureaucrat( void );
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const Bureaucrat& copy );

		// Destructor
		~Bureaucrat( void );

		// Operator
		Bureaucrat&	operator=( const Bureaucrat& copy );

		// Functions
		//Getters
		const std::string&	getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );

		void				signForm( Form& f );

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
		int					_grade;
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& b );


// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif
