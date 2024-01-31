
#include "ScalarConverter.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "convert: no arguments" << std::endl;
		return (1);
	}

	std::string input(argv[1]);
	try
	{
		ScalarConverter::convert(input);
	}
	catch (std::exception &e)
	{
		std::cerr << "convert: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
