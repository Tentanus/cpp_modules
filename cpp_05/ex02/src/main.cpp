
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

#define MSG_BORDER "-----------------------------------------------"

bool t_constructors(Bureaucrat **B1, Bureaucrat **B2, Bureaucrat **B3)
{
	try
	{
		*B1 = new Bureaucrat("Jake", 143);
		*B2 = new Bureaucrat("William", 70);
		*B3 = new Bureaucrat("POTUS Agatha", 2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}

	return (true);
}

bool t_signing(Bureaucrat &Intern, Bureaucrat &Secretary, Bureaucrat &President,
			   AForm &memo, AForm &decree, AForm &pardon)
{
	try
	{
		Intern.signForm(memo);
		Secretary.signForm(decree);

		President.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}

	return (true);
}

bool t_execute(Bureaucrat &Intern, Bureaucrat &Secretary, Bureaucrat &President,
			   AForm &memo, AForm &decree, AForm &pardon)
{
	(void)Intern;
	try
	{
		memo.execute(Secretary);
		std::cout << "\n";
		decree.execute(Secretary);
		std::cout << "\n";
		pardon.execute(President);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}

	return (true);
}

void free_resources(Bureaucrat *Intern, Bureaucrat *Secretary,
					Bureaucrat *President, AForm *memo, AForm *decree,
					AForm *pardon)
{
	delete Intern;
	delete Secretary;
	delete President;
	delete memo;
	delete decree;
	delete pardon;
}

int main()
{
	Bureaucrat *AdministrativeIntern;
	Bureaucrat *Secretary;
	Bureaucrat *President;

	if (!t_constructors(&AdministrativeIntern, &Secretary, &President))
		return (1);

	std::cout << MSG_BORDER << "\n" << std::endl;
	std::cout << "\nOUTPUT: \n";

	std::cout << *AdministrativeIntern << std::endl;
	std::cout << *Secretary << std::endl;
	std::cout << *President << std::endl;

	std::cout << "\n\n" << MSG_BORDER << "\n" << std::endl;

	AForm *memo = new ShrubberyCreationForm("file");
	AForm *decree = new RobotomyRequestForm("AdministrativeIntern");
	AForm *pardon = new PresidentialPardonForm("Secretary William");

	std::cout << "\n\n" << MSG_BORDER << "\n" << std::endl;

	if (!t_signing(*AdministrativeIntern, *Secretary, *President, *memo,
				   *decree, *pardon))
		return (free_resources(AdministrativeIntern, Secretary, President, memo,
							   decree, pardon),
				1);

	std::cout << "\n\n" << MSG_BORDER << "\n" << std::endl;

	if (!t_execute(*AdministrativeIntern, *Secretary, *President, *memo,
				   *decree, *pardon))
		return (free_resources(AdministrativeIntern, Secretary, President, memo,
							   decree, pardon),
				1);

	std::cout << "\n\n" << MSG_BORDER << "\n" << std::endl;

	free_resources(AdministrativeIntern, Secretary, President, memo, decree,
				   pardon);

	return (0);
}
