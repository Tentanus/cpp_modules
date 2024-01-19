
#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>
#include <string>

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	std::cout << bur.getName() << ", Bureaucrat grade " << bur.getGrade();
	return (out);
}

//-------------------Orthodox Canonical Form-------------------//

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
#ifdef MSG
	std::cout << "Called\tBureaucrat\tConstructor:\tDefault" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tBureaucrat\tConstructor:\tNamed" << std::endl;
#endif

	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
	: _name(rhs._name), _grade(rhs._grade)
{
#ifdef MSG
	std::cout << "Called\tBureaucrat\tConstructor:\tCopy" << std::endl;
#endif
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
#ifdef MSG
	std::cout << "Called\tBureaucrat\tCopy Assignment operator" << std::endl;
#endif
	if (this == &rhs)
		return (*this);

	_name = rhs._name;
	_grade = rhs._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
#ifdef MSG
	std::cout << "Called\tBureaucrat\tDeconstructor" << std::endl;
#endif
}
