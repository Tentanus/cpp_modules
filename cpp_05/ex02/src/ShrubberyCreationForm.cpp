
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

#include <fstream>
#include <ios>
#include <iostream>
#include <string>

void ShrubberyCreationForm::execute(const Bureaucrat &bur)
{
	AForm::execute(bur);

	std::fstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	std::string filename = getTarget() + "_shrubbery";

	file.open(filename.c_str(), std::ios_base::out);

	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();

	file << ASCII_TREE;
	file.close();
}

const std::string ShrubberyCreationForm::getTarget()
{
	return (_target);
}

//-------------------Orthodox Canonical Form-------------------//

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC), _target()
{
#ifdef MSG
	std::cout << "Called\tShrubberyCreationForm\tConstructor:\tDefault"
			  << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", SHRUB_SIGN, SHRUB_EXEC), _target(target)
{
#ifdef MSG
	std::cout << "Called\tShrubberyCreationForm\tConstructor:\tNamed"
			  << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: AForm(rhs.getName(), rhs.getSigningGrade(), rhs.getExecuteGrade()),
	  _target(rhs._target)
{
#ifdef MSG
	std::cout << "Called\tShrubberyCreationForm\tConstructor:\tCopy"
			  << std::endl;
#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef MSG
	std::cout << "Called\tShrubberyCreationForm\tDeconstructor" << std::endl;
#endif
}
