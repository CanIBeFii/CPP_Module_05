#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
	// {
	// 	try {
	// 		Bureaucrat bob( "Bob", 2 );
	// 		std::cout << bob << std::endl;

	// 		bob.incrementGrade();

	// 		std::cout << bob << std::endl;

	// 		bob.incrementGrade();

	// 		std::cout << bob << std::endl;

	// 	} catch ( std::exception& e ) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		Bureaucrat bob( "Bob", 149 );
	// 		std::cout << bob << std::endl;

	// 		bob.decrementGrade();

	// 		std::cout << bob << std::endl;

	// 		bob.decrementGrade();

	// 		std::cout << bob << std::endl;

	// 	} catch ( std::exception& e ) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		Bureaucrat bob( "Bob", -1 );
	// 	} catch ( std::exception& e ) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		Bureaucrat bob( "Bob", 151 );
	// 	} catch ( std::exception& e ) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	{
		try {
			Form form( "Form", 10, 152 );
		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form form( "Form", 0, 15 );
		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form form( "Form", 10, 150 );
			Form form2( "form2", 30, 140 );

			Bureaucrat	bob( "BOB", 5 );

			bob.signForm( form );

			std::cout << "Is form signed: " << form2.getSigned() << std::endl;

			form2 = form;

			std::cout << "Is form signed: " << form2.getSigned() << std::endl;
		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form form( "Form", 50 , 100 );

			std::cout << form << std::endl;

			Bureaucrat carl( "Carl", 51 );

			std::cout << carl << std::endl;

			carl.signForm( form );

		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	return ( 0 );
}