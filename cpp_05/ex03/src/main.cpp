
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

#define MSG_BORDER "-----------------------------------------------"

int main()
{
	Intern someRandomIntern;
	Bureaucrat Overlord("C'thulu", 1);
	AForm *rrf;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern was unable to make form [" << e.what() << "].";
	}

	Overlord.signForm(*rrf);
	rrf->execute(Overlord);

	return (0);
}
