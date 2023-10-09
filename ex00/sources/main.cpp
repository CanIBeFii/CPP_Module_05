#include "../includes/Bureaucrat.hpp"

int main( void ) {
	{
		try {
			Bureaucrat bob( "Bob", 2 );
			std::cout << bob << std::endl;

			bob.incrementGrade();

			std::cout << bob << std::endl;

			bob.incrementGrade();

			std::cout << bob << std::endl;

		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bob( "Bob", 149 );
			std::cout << bob << std::endl;

			bob.decrementGrade();

			std::cout << bob << std::endl;

			bob.decrementGrade();

			std::cout << bob << std::endl;

		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bob( "Bob", -1 );
		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat bob( "Bob", 151 );
		} catch ( std::exception& e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}