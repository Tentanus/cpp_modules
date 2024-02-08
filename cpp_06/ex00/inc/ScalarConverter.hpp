#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits.h>

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	virtual ScalarConverter &operator=(const ScalarConverter &rhs) = 0;
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string &input);

	template <typename T>
	static void printType(T type)
	{
		std::cout << "Char:\t"
		printChar(t);
		std::cout << "Int:\t"
		printInt(t);
		std::cout << "Float:\t"
		printFloat(t);
		std::cout << "Double:\t"
		printDouble(t);
		std::cout << std::endl;
	}

	template <typename T> void printInt(T t)
	{

		std::cout << "\n";
	}

	template <typename T> void printChar(T t)
	{
		if (!isnan(t) || t < CHAR_MIN || t > CHAR_MAX)
			std::cout << "impossible";
		if (!isprint(t))
			std::cout << "Non-printable";
		else
			std::cout << static_cast<char>(t);
		std::cout << "\n";
	}
};

#endif // !SCALARCONVERTER_HPP
