#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>

class Form
{
  private:
	const std::string _name;
	const int _grade_sign;
	const int _grade_exec;
	bool _signed;

	Form &operator=(const Form &rhs); // Impossible, due to const values;

  public:
	Form();
	Form(std::string name, int grade_sign, int grade_exec);
	Form(const Form &rhs);
	~Form();

	std::string getName() const;
	int getSigningGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &bur);

	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Form Exception : Grade is too high." NC);
		};
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Form Exception : Grade is too Low." NC);
		};
	};
};

std::ostream &operator<<(std::ostream &out, const Form &bur);

#endif // !FORM_HPP
