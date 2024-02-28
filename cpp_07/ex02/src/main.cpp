
#include "Array.hpp"
#include <stdlib.h>
#include <string>
#include <time.h>

#define MAX_VAL 10

int main(void)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 300;
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "Array:\tmirror: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
		else
			std::cout << numbers[i] << "\t" << mirror[i] << std::endl;
	}

	delete[] mirror;

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	{
		Array<int> test(numbers);

		for (int i = 0; i < MAX_VAL; i++)
			numbers[i] = rand() % 70;

		std::cout << "numbers:\t" << numbers << std::endl;
		std::cout << "test:\t" << test << std::endl;
	}

	/*
	 * requires C++11
		Array<std::string> strings(5);

		for (int i = 0; i < 5; i++)
			strings[i] = "TEST_0" + std::to_string(i);

		std::cout << "strings:\t" << strings << std::endl;
	*/
	return 0;
}
