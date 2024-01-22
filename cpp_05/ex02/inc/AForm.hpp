#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>

class AForm
{
  private:
	const std::string _name;
	const int _grade_sign;
	const int _grade_exec;
	bool _signed;

	AForm &operator=(const AForm &rhs); // Impossible, due to const values;

  public:
	AForm();
	AForm(std::string name, int grade_sign, int grade_exec);
	AForm(const AForm &rhs);
	virtual ~AForm() = 0;

	std::string getName() const;
	int getSigningGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &bur);
	virtual void execute(const Bureaucrat &bur) = 0;

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

	class FormNotSignedException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Form Exception : Form Not Signed" NC);
		};
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &bur);

#endif // !FORM_HPP
