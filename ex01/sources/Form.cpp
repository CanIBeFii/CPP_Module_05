#include "Form.hpp"

// Constructors
Form::Form( void ) : _name( "Default" ), _signerGrade( 150 ), _executeGrade( 150 ) {
	std::cout << BOLDCYAN << "Form: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	_signed = false;
}

Form::Form( const std::string& name, int signerGrade, int executeGrade ) :
		_name( name ), _signerGrade( signerGrade ), _executeGrade( executeGrade ) {
	std::cout << BOLDCYAN << "Form: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET; 
	std::cout << " called" << std::endl;

	if ( _signerGrade < 1 || _executeGrade < 1 ) {
		throw Form::GradeTooHighException();
	}
	if ( _signerGrade > 150 || _executeGrade > 150 ) {
		throw Form::GradeTooLowException();
	}

	_signed = false;
}

Form::Form( const Form& copy ) : _name( copy._name ),
		_signerGrade( copy._signerGrade ), _executeGrade( copy._executeGrade ) {
	std::cout << BOLDCYAN << "Form: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	_signed = copy._signed;
}

// Destructors
Form::~Form( void ) {
	std::cout << BOLDCYAN << "Form: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
Form&	Form::operator=( const Form& copy ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		_signed = copy._signed;
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	Form::getName( void ) const {
	return ( _name );
}

bool	Form::getSigned( void ) const {
	return ( _signed );
}

int		Form::getSignerGrade( void ) const {
	return ( _signerGrade );
}

int		Form::getExecuteGrade( void ) const {
	return ( _executeGrade );
}


void	Form::beSigned( Bureaucrat& b ) {
	if ( b.getGrade() > _signerGrade ) {
		throw Form::GradeTooLowException();
	}
	_signed = true;
}

// Exceptions
const char*	Form::GradeTooHighException::what( void ) const throw() {
	return ( "Grade too high" );
}

const char*	Form::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
}

// Ostream
std::ostream&	operator<<( std::ostream& out, const Form& f ) {
	out << "Form: " << f.getName() << ", signed: " << f.getSigned();
	out << ", signer grade: " << f.getSignerGrade();
	out << ", execute grade: " << f.getExecuteGrade();
	return ( out );
}