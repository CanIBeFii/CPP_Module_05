#include "../includes/Intern.hpp"

// Constructors
Intern::Intern( void ) {
	std::cout << BOLDCYAN << "Intern: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Intern::Intern( const Intern& copy ) {
	std::cout << BOLDCYAN << "Intern: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	*this = copy;
}

// Destructors
Intern::~Intern( void ) {
	std::cout << BOLDCYAN << "Intern: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
Intern&	Intern::operator=( const Intern& copy ) {
	std::cout << BOLDCYAN << "Intern: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		(void)copy;
	}
	return ( *this );
}

// Functions

static AForm*	makePresidentialPardonForm( const std::string& target ) {
	return ( new PresidentialPardonForm( target ) );
}

static AForm*	makeRobotomyRequestForm( const std::string& target ) {
	return ( new RobotomyRequestForm( target ) );
}

static AForm*	makeShrubberyCreationForm( const std::string& target ) {
	return ( new ShrubberyCreationForm( target ) );
}

AForm*	Intern::makeForm( const std::string& name, const std::string& target ) {
	std::string formNames[] = { "Presidential Pardon", "Robotomy Request", "Shrubbery Creation" };
	AForm*	(*functions[])( const std::string& target ) = { &makePresidentialPardonForm,
		&makeRobotomyRequestForm, &makeShrubberyCreationForm };
	
	for ( int i = 0; i < 3; i++ ) {
		if ( name.compare( formNames[i] ) == 0 ) {
			std::cout << "Intern will create a " << formNames[i] << " form" << std::endl;
			return ( functions[i]( target ) ); 
		}
	}
	throw Intern::FormNotFoundException();
}

// Exceptions
const char*	Intern::FormNotFoundException::what( void ) const throw() {
	return ( "Form not found" );
}