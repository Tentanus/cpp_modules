
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makeForm(const std::string formname, const std::string target)
{
	if (formname == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else if (formname == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (formname == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
		throw UnableToFindForm();
}

//-------------------Orthodox Canonical Form-------------------//

Intern::Intern()
{
#ifdef MSG
	std::cout << "Called\tIntern\t\t\tConstructor:\tDefault" << std::endl;
#endif
}

Intern::Intern(const Intern &rhs)
{
#ifdef MSG
	std::cout << "Called\tIntern\t\t\tConstructor:\tCopy" << std::endl;
#endif

	(void)rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
#ifdef MSG
	std::cout << "Called\tIntern\t\t\tCopy Assignment operator" << std::endl;
#endif

	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
#ifdef MSG
	std::cout << "Called\tIntern\t\t\tDeconstructor" << std::endl;
#endif
}
