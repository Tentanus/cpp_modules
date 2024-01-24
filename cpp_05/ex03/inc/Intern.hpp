#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include <string>

class Intern
{
  private:
  public:
	Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);
	~Intern();

	AForm *makeForm(const std::string formname, const std::string target);

	class UnableToFindForm : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Intern Exception : Unkown formname." NC);
		};
	};
};

#endif // !INTERN_HPP
