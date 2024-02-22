#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string>

enum type_id
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE,
	ERROR
};

const std::string id_names[ERROR] = {
	"Character", "Integer", "Float", "Double", "Impossible",
};

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	virtual ScalarConverter &operator=(const ScalarConverter &rhs) = 0;
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string &input);

  private:
	// TODO: make sure class has only one static member function;
	void printImpossible(void);
	static void printType(const std::string &str)
	{
		std::cout << "Char:\t";
		printChar(str[0]);
		std::cout << "Int:\t";
		printInt(std::strtol(str.c_str(), NULL, 10));
		std::cout << "Float:\t";
		printFloat(std::strtof(str.c_str(), NULL));
		std::cout << "Double:\t";
		printDouble(std::strtod(str.c_str(), NULL));
		std::cout << std::flush;
	}

	template <typename T>
	static void printDouble(T t)
	{
		std::cout << static_cast<double>(t);
		if (t - static_cast<double>(t) == 0)
			std::cout << .0;

		std::cout << "\n";
	}

	template <typename T>
	static void printFloat(T t)
	{
		std::cout << static_cast<float>(t);
		if (t - static_cast<float>(t) == 0)
			std::cout << .0;
		std::cout << 'f';

		std::cout << "\n";
	}

	template <typename T>
	static void printInt(T t)
	{
		if (std::isnan(t) || t < INT_MIN || t > INT_MAX)
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(t);

		std::cout << "\n";
	}

	template <typename T>
	static void printChar(T t)
	{
		if (std::isnan(t) || t < CHAR_MIN || t > CHAR_MAX)
			std::cout << "impossible";
		else if (!isprint(t))
			std::cout << "Non-printable";
		else
			std::cout << static_cast<char>(t);

		std::cout << "\n";
	}
};

#endif // !SCALARCONVERTER_HPP
