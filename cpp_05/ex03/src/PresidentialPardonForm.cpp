
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#include <iostream>

const std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &bur)
{
	AForm::execute(bur);

	std::cout << getTarget()
			  << " has been pardoned by President Zaphod Beeblebrox"
			  << std::endl;
}

//-------------------Orthodox Canonical Form-------------------//

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", PARD_SIGN, PARD_EXEC), _target("")
{
#ifdef MSG
	std::cout << "Called\tPresidentialPardonForm\tConstructor:\tDefault"
			  << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", PARD_SIGN, PARD_EXEC), _target(target)
{
#ifdef MSG
	std::cout << "Called\tPresidentialPardonForm\tConstructor:\tNamed"
			  << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &rhs)
	: AForm(rhs.getName(), rhs.getSigningGrade(), rhs.getExecuteGrade()),
	  _target(rhs.getTarget())
{
#ifdef MSG
	std::cout << "Called\tPresidentialPardonForm\tConstructor:\tCopy"
			  << std::endl;
#endif
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
#ifdef MSG
	std::cout << "Called\tPresidentialPardonForm\tCopy Assignment operator"
			  << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_target = rhs.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef MSG
	std::cout << "Called\tPresidentialPardonForm\tDeconstructor" << std::endl;
#endif
}
