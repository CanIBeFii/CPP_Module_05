#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		// Constructors
		Intern( void );
		Intern( const Intern& copy );

		// Destructor
		~Intern( void );

		// Operators
		Intern&	operator=( const Intern& copy );

		// Functions
		AForm*	makeForm( const std::string& name, const std::string& target );

		class FormNotFoundException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};
};

#endif