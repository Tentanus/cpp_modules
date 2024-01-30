#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	static void convert(const std::string input);

  private:
	template <typename T>
	static void printChar(T c)
	{
		if (std::isnan(c) || c < CHAR_MIN || c > CHAR_MAX)
			std::cout << "Impossible";
		else if (std::isprint(static_cast<char>(c)))
			std::cout << static_cast<char>(c);
		else
			std::cout << "Non Displayable";
	}

	template <typename T>
	static void printInt(T i)
	{
		if (std::isnan(i) || i < INT_MAX || i > INT_MAX)
			std::cout << "Impossible";
		else
			std::cout << static_cast<int>(i);
	}

	template <typename T>
	static void printFloat(T f)
	{
		std::cout <<
	}

	template <typename T>
	static void printDouble(T d)
	{
	}
};

#endif // !SCALARCONVERTER_HPP
