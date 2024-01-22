
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

#define MSG_BORDER "-----------------------------------------------"

bool t_constructors(Bureaucrat **B1, Bureaucrat **B2)
{
	try
	{
		*B1 = new Bureaucrat("Jimmy", 40);
		*B2 = new Bureaucrat("James", 80);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}

	return (true);
}

bool t_signing(Bureaucrat &B1, Bureaucrat &B2)
{
	(void)B1;
	(void)B2;

	return (true);
}

int main()
{
	Bureaucrat *B1;
	Bureaucrat *B2;

	if (!t_constructors(&B1, &B2))
		return (1);

	std::cout << MSG_BORDER << std::endl;
	std::cout << "\nOUTPUT: \n";

	std::cout << *B1 << std::endl;
	std::cout << *B2 << std::endl;

	std::cout << "\n" << MSG_BORDER << std::endl;

	if (!t_signing(*B1, *B2))
		return (1);

	return (0);
}
