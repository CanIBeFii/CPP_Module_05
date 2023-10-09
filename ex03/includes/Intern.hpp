#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

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