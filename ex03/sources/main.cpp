#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include <cstdlib>

int main( void ) {
	srand( time( NULL ) );
	{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");

		delete rrf;

		rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");

		delete rrf;

		rrf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");

		delete rrf;
	}
	{
		try {
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("Give me a Form", "Bender");
		} catch ( Intern::FormNotFoundException& e ) {
			std::cerr << e.what() << std::endl;
		}
	}

	return ( 0 );
}