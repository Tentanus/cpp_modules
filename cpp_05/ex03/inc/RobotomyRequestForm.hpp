#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define ROBO_SIGN 72
#define ROBO_EXEC 45

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	const std::string getTarget() const;
	void execute(const Bureaucrat &bur);
};
#endif // !ROBOTOMYREQUESTFORM_HPP
