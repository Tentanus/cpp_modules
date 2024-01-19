
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat Burarray[4];
		int numbers[4] = {1, 1, 150, 150};
		// int numbers[4] = {0, 1, 150, 151};

		for (size_t i = 0; i < 4; i++)
			Burarray[i] = Bureaucrat("Bob", numbers[i]);

		Burarray[1].decreaseGrade();
		Burarray[2].increaseGrade();

		for (size_t i = 0; i < 4; i++)
			std::cout << Burarray[i] << std::endl;

		// Burarray[3].decreaseGrade();
		// Burarray[0].increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
