#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

//-------------------Color------------------//

#define NC "\x1B[0m"
#define WHT "\x1B[0;37m" // White
#define RED "\x1B[0;31m" // Red

//-------------------Class------------------//

class Bureaucrat
{
  private:
	std::string _name;
	int _grade;

  public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Bureaucrat Exception : Grade is too high." NC);
		};
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what() const throw()
		{
			return (RED "Bureaucrat Exception : Grade is too Low." NC);
		};
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

#endif // !BUREAUCRAT_HPP
