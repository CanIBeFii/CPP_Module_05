#include "AForm.hpp"

// Constructors
AForm::AForm( void ) : _name( "Default" ), _signerGrade( 150 ), _executeGrade( 150 ) {
	std::cout << BOLDCYAN << "AForm: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	_signed = false;
}

AForm::AForm( const std::string& name, int signerGrade, int executeGrade ) :
		_name( name ), _signerGrade( signerGrade ), _executeGrade( executeGrade ) {
	std::cout << BOLDCYAN << "AForm: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET; 
	std::cout << " called" << std::endl;

	_signed = false;
}

AForm::AForm( const AForm& copy ) : _name( copy._name ),
		_signerGrade( copy._signerGrade ), _executeGrade( copy._executeGrade ) {
	std::cout << BOLDCYAN << "AForm: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	_signed = copy._signed;
}

// Destructors
AForm::~AForm( void ) {
	std::cout << BOLDCYAN << "AForm: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
AForm&	AForm::operator=( const AForm& copy ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		_signed = copy._signed;
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	AForm::getName( void ) const {
	return ( _name );
}

bool	AForm::getSigned( void ) const {
	return ( _signed );
}

int		AForm::getSignerGrade( void ) const {
	return ( _signerGrade );
}

int		AForm::getExecuteGrade( void ) const {
	return ( _executeGrade );
}

void	AForm::beSigned( Bureaucrat& b ) {
	if ( b.getGrade() > _signerGrade ) {
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

// Exceptions
const char*	AForm::GradeTooHighException::what( void ) const throw() {
	return ( "Grade too high" );
}

const char*	AForm::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
}

// Ostream
std::ostream&	operator<<( std::ostream& out, const AForm& f ) {
	out << "AForm: " << f.getName() << ", signed: " << f.getSigned();
	out << ", signer grade: " << f.getSignerGrade();
	out << ", execute grade: " << f.getExecuteGrade();
	return ( out );
}