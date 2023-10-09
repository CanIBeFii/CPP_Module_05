#include "../includes/Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat( void ) : _name( "Default" ), _grade( 150 ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name( name ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET; 
	std::cout << " called" << std::endl;

	if ( grade < 1 ) {
		throw Bureaucrat::GradeTooHighException();
	}
	if ( grade > 150 ) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : _name( copy.getName() ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;

	*this = copy;
}

// Destructors
Bureaucrat::~Bureaucrat( void ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy ) {
	std::cout << BOLDCYAN << "Bureaucrat: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		_grade = copy.getGrade();
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	Bureaucrat::getName( void ) const {
	return ( _name );
}

int	Bureaucrat::getGrade( void ) const {
	return ( _grade );
}


void	Bureaucrat::incrementGrade( void ) {
	if ( _grade - 1 < 1 ) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade -= 1;
}

void	Bureaucrat::decrementGrade( void ) {
	if ( _grade + 1 > 150 ) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade += 1;
}

void	Bureaucrat::signForm( AForm& f ) {
	try {
		f.beSigned( *this );

		std::cout << getName() << " signed " << f.getName() << std::endl;
	} catch ( AForm::GradeTooLowException& e ) {
		std::cout << getName() << " couldn't sign " << f.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( const AForm& form ) {
	try {
		form.execute( *this );
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch ( std::exception& e ) {
		std::cerr << getName() << " couldn't execute form because " << e.what() << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ( "\033[1m\033[31mException:\033[0m Grade too high!!");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ( "\033[1m\033[31mException:\033[0m Grade too low!!");
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b ) {
	out << b.getName() << ", bureacrat grade " << b.getGrade() << ".";
	return ( out );
}