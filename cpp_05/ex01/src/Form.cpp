
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
	if (bur.getGrade() < getSigningGrade())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::cout << "Form: signed [" << (form.isSigned() ? "x" : " ") << "]\n"
			  << "Signing Grade:\t" << form.getSigningGrade() << "\n"
			  << "Execution Grade:\t" << form.getExecuteGrade();

	return (out);
}

//-------------------Orthodox Canonical Form-------------------//

Form::Form(std::string name, int grade_sign, int grade_exec)
	: _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec),
	  _signed(false)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &rhs)
	: _name(rhs._name), _grade_sign(rhs._grade_sign),
	  _grade_exec(rhs._grade_exec), _signed(rhs._signed)
{
}

/*
Form &Form::operator=(const Form &rhs)
{
}
*/

Form::~Form()
{
}
