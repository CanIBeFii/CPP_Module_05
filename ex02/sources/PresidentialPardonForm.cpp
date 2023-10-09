#include "../includes/PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "Presidential Pardon", 25, 5 ), _target( "default" ) {
	std::cout << BOLDCYAN << "PresidentialPardonForm: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm( "Presidential Pardon", 25, 5 ),
		_target( target ) {
	std::cout << BOLDCYAN << "PresidentialPardonForm: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET;
	std::cout << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm( copy ), _target( copy._target ) {
	std::cout << BOLDCYAN << "PresidentialPardonForm: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << BOLDCYAN << "PresidentialPardonForm: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy ) {
	std::cout << BOLDCYAN << "PresidentialPardonForm: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		AForm::operator=( copy );
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	PresidentialPardonForm::getTarget( void ) const {
	return ( _target );
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
	if ( getSigned() == false ) {
		throw PresidentialPardonForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getExecuteGrade() ) {
		throw PresidentialPardonForm::GradeTooLowException();
	}

	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

// Exceptions
const char*	PresidentialPardonForm::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
}

const char*	PresidentialPardonForm::FormNotSignedException::what( void ) const throw() {
	return ( "Form is not signed" );
}
