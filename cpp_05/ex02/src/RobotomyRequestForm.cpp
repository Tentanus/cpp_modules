
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

#include <cstdlib>
#include <iostream>

const std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &bur)
{
	AForm::execute(bur);

	std::cout << "zzzzzzzzzzzzzzzzzZZZZZZZZZZZZZZZZZ" << std::endl;

	if (std::rand() % 2)
		std::cout << getTarget()
				  << " was succesfully Robotomized. Hail Megatron.\n"
				  << getTarget() << ": Hail Megatron" << std::endl;
	else
		std::cout << getTarget()
				  << " has resited our Decepticon overlords. Start Invation."
				  << std::endl;
}

//-------------------Orthodox Canonical Form-------------------//

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXEC), _target("")
{
#ifdef MSG
	std::cout << "Called\tRobotomyRequestForm\tConstructor:\tDefault"
			  << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", ROBO_SIGN, ROBO_EXEC), _target(target)
{
#ifdef MSG
	std::cout << "Called\tRobotomyRequestForm\tConstructor:\tNamed"
			  << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
	: AForm(rhs.getName(), rhs.getSigningGrade(), rhs.getExecuteGrade()),
	  _target(rhs.getTarget())
{
#ifdef MSG
	std::cout << "Called\tRobotomyRequestForm\tConstructor:\tCopy" << std::endl;
#endif
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
#ifdef MSG
	std::cout << "Called\tRobotomyRequestForm\tCopy Assignment operator"
			  << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_target = rhs.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef MSG
	std::cout << "Called\tRobotomyRequestForm\tDeconstructor" << std::endl;
#endif
}
