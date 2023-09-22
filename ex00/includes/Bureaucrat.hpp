#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
		const std::string&	getName( void );
		int					getGrade( void );

		void				incrementGrade( void );
		void				decrementGrade( void );

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

#endif