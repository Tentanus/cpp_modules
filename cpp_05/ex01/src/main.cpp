
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

#define MSG_BORDER "-----------------------------------------------"

bool t_constructors(Bureaucrat **B1, Bureaucrat **B2, Bureaucrat**B3, Form **F1)
{
	try
	{
		*B1 = new Bureaucrat("Jimmy", 40);
		*B2 = new Bureaucrat("Johny", 60);
		*B3 = new Bureaucrat("James", 80);
		*F1 = new Form("Garbage License", 75, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}

	return (true);
}

bool t_signing(Bureaucrat &B1, Bureaucrat &B2, Bureaucrat &B3, Form &F1)
{
	B3.signForm(F1);
	std::cout << "\n" << F1 << std::endl;
	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;
	B2.signForm(F1);
	std::cout << "\n" << F1 << std::endl;
	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;
	B1.signForm(F1);
	std::cout << "\n" << F1 << std::endl;
	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;
	return (true);
}

int main()
{
	Bureaucrat *B1;
	Bureaucrat *B2;
	Bureaucrat *B3;
	Form *F1;

	if (!t_constructors(&B1, &B2, &B3, &F1))
		return (1);

	std::cout << MSG_BORDER << std::endl;
	std::cout << "\nOUTPUT: \n";
	std::cout << *B1 << std::endl;
	std::cout << *B2 << std::endl;
	std::cout << *B3 << std::endl;
	std::cout << *F1 << std::endl;
	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	if (!t_signing(*B1, *B2, *B3, *F1))
		return (1);

	return (0);
}
