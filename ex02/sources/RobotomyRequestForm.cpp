#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm( "Robotomy Request", 72, 45 ), _target( "default" ) {
	std::cout << BOLDCYAN << "RobotomyRequestForm: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm( "Robotomy Request", 72, 45 ),
		_target( target ) {
	std::cout << BOLDCYAN << "RobotomyRequestForm: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET;
	std::cout << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm( copy ), _target( copy._target ) {
	std::cout << BOLDCYAN << "RobotomyRequestForm: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << BOLDCYAN << "RobotomyRequestForm: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy ) {
	std::cout << BOLDCYAN << "RobotomyRequestForm: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		AForm::operator=( copy );
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	RobotomyRequestForm::getTarget( void ) const {
	return ( _target );
}


void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
	if ( getSigned() == false ) {
		throw RobotomyRequestForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getExecuteGrade() ) {
		throw RobotomyRequestForm::GradeTooLowException();
	}

	if ( rand() % 2 == 0 ) {
		std::cout << "Frrrrmmm " << _target << " has been robotomized successfully" << std::endl; 
	}
	else {
		std::cout << "Frrmmmmm BOOOOOMMMM " << _target << " oh nooo robotomized failed" << std::endl;
	}
}

// Exceptions
const char*	RobotomyRequestForm::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
}

const char*	RobotomyRequestForm::FormNotSignedException::what( void ) const throw() {
	return ( "Form is not signed" );
}
