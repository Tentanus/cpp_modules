#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	virtual ScalarConverter &operator=(const ScalarConverter &rhs) = 0;
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string &input);

	private:
	template <typename T>
		
	void printType(T t)
	{
		std::cout << "Char:\t";
		printChar(t);
		std::cout << "Int:\t";
		printInt(t);
		std::cout << "Float:\t";
		printFloat(t);
		std::cout << "Double:\t";
		printDouble(t);
		std::cout << std::endl;
	}

	template <typename T> void printInt(T t)
	{
		if (!std::isnan(t) || t < INT_MIN || t > INT_MAX)
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(t);

		std::cout << "\n";
	}

	template <typename T> void printChar(T t)
	{
		if (!std::isnan(t) || t < CHAR_MIN || t > CHAR_MAX)
			std::cout << "impossible";
		if (!isprint(t))
			std::cout << "Non-printable";
		else
			std::cout << static_cast<char>(t);
		std::cout << "\n";
	}
};

#endif // !SCALARCONVERTER_HPP
