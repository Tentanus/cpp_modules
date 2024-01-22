
#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

std::string Form::getName() const
{
	return (_name);
}

int Form::getSigningGrade() const
{
	return (_grade_sign);
}

int Form::getExecuteGrade() const
{
	return (_grade_exec);
}

bool Form::isSigned() const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &bur)
{
	std::cout << "Checking grades:\nBureaucrat\t[" << bur.getGrade() << "]\n"
			  << "Form\t\t[" << getSigningGrade() << "]" << std::endl;

	if (bur.getGrade() > getSigningGrade())
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::cout << "Form: " << form.getName() << "\nsigned ["
			  << (form.isSigned() ? "x" : " ") << "]\n"
			  << "Signing Grade:\t\t" << form.getSigningGrade() << "\n"
			  << "Execution Grade:\t" << form.getExecuteGrade();

	return (out);
}

//-------------------Orthodox Canonical Form-------------------//

Form::Form() : _name(), _grade_sign(150), _grade_exec(150), _signed(false)
{
#ifdef MSG
	std::cout << "Called\tForm\t\tConstructor:\tDefault" << std::endl;
#endif
}

Form::Form(std::string name, int grade_sign, int grade_exec)
	: _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec),
	  _signed(false)
{
#ifdef MSG
	std::cout << "Called\tForm\t\tConstructor:\tNamed" << std::endl;
#endif

	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &rhs)
	: _name(rhs._name), _grade_sign(rhs._grade_sign),
	  _grade_exec(rhs._grade_exec), _signed(rhs._signed)
{
#ifdef MSG
	std::cout << "Called\tForm\t\tConstructor:\tCopy" << std::endl;
#endif
}

/*
Form &Form::operator=(const Form &rhs)
{
#ifdef MSG
	std::cout << "Called\tForm\tCopy Assignment operator" << std::endl;
#endif
Not possible due to there being constants.
}
*/

Form::~Form()
{
#ifdef MSG
	std::cout << "Called\tForm\t\tDeconstructor" << std::endl;
#endif
}
