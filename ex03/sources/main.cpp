#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void ) {
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