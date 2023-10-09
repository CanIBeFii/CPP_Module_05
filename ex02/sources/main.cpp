#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <cstdlib>

int main( void ) {

	srand( time( NULL ) );
	
	ShrubberyCreationForm s("Shrubbery");
	RobotomyRequestForm r("Robotomy");
	PresidentialPardonForm p("Presidential");
	Bureaucrat b("bureaucrat", 2);

	try
	{
		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try
	{
		s.beSigned(b);
		r.beSigned(b);
		p.beSigned(b);

		b.executeForm(s);
		std::cout << std::endl;

		b.executeForm(r);
		std::cout << std::endl;
		
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	try
	{
		s.beSigned(b);
		std::cout << "+++++++++++" << std::endl;
		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}