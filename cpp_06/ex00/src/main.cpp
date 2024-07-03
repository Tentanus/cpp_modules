
#include "ScalarConverter.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "convert: give 1 arguments" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}
