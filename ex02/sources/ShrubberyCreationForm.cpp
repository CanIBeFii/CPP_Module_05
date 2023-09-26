#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "Shrubbery Creation", 145, 137 ), _target( "default" ) {
	std::cout << BOLDCYAN << "ShrubberyCreationForm: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( "Shrubbery Creation", 145, 137 ),
		_target( target ) {
	std::cout << BOLDCYAN << "ShrubberyCreationForm: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor" << RESET;
	std::cout << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm( copy ), _target( copy._target ) {
	std::cout << BOLDCYAN << "ShrubberyCreationForm: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << BOLDCYAN << "ShrubberyCreationForm: " << RESET;
	std::cout << BOLDRED << " Destructor " << RESET << "called" << std::endl;
}

// Operators
ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy ) {
	std::cout << BOLDCYAN << "ShrubberyCreationForm: " << RESET;
	std::cout << BOLDYELLOW << "Assignation Operator" << RESET << " called" << std::endl;

	if ( this != &copy ) {
		AForm::operator=( copy );
	}
	return ( *this );
}

// Functions
// Getters
const std::string&	ShrubberyCreationForm::getTarget( void ) const {
	return ( _target );
}


void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if ( getSigned() == false ) {
		throw ShrubberyCreationForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getExecuteGrade() ) {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	std::string		target = _target;
	std::ofstream	file( target.append( "_shrubbery" ).c_str(), std::ofstream::out );
	file << "                                                         .\n";
	file << "                                              .         ;  \n";
	file << "                 .              .              ;%     ;;   \n";
	file << "                   ,           ,                :;%  %;   \n";
	file << "                    :         ;                   :;%;'     .,\n";
	file << "           ,.        %;     %;            ;        %;'    ,;\n";
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
	file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
	file << "                    `:%;.  :;bd%;          %;@%;'\n";
	file << "                      `@%:.  :;%.         ;@@%;'\n";
	file << "                        `@%.  `;@%.      ;@@%;\n";
	file << "                          `@%%. `@%%    ;@@%;\n";
	file << "                            ;@%. :@%%  %@@%;\n";
	file << "                              %@bd%%%bd%%:;\n";
	file << "                                #@%%%%%:;;\n";
	file << "                                %@@%%%::;\n";
	file << "                                %@@@%(o);  . '\n";
	file << "                                %@@@o%;:(.,'\n";
	file << "                            `.. %@@@o%::;\n";
	file << "                               `)@@@o%::;\n";
	file << "                                %@@(o)::;\n";
	file << "                               .%@@@@%::;\n";
	file << "                               ;%@@@@%::;.\n";
	file << "                              ;%@@@@%%:;;;.\n";
	file << "                          ...;%@@@@@%%:;;;;,..";
	file.close();
}


// Exceptions
const char*	ShrubberyCreationForm::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
}

const char*	ShrubberyCreationForm::FormNotSignedException::what( void ) const throw() {
	return ( "Form is not signed" );
}