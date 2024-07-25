#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string>

#define UCHAR_MIN 0
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
	"CHAR", "INT", "FLOAT", "DOUBLE", "IMPOSSIBLE",
};

class ScalarConverter
{
  public:
	ScalarConverter(const ScalarConverter &rhs);
	virtual ScalarConverter &operator=(const ScalarConverter &rhs) = 0;
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string input);

	template <typename T>
	static void printChar(T t)
	{
		char c = static_cast<char>(t);
		if (std::isnan(t) || static_cast<int>(t) < UCHAR_MIN ||
			static_cast<int>(t) > CHAR_MAX)
			std::cout << "Impossible";
		else if (!isprint(static_cast<char>(t)) || c == '\0')
			std::cout << "Non-printable";
		else
			std::cout << c;

		std::cout << "\n";
	}

	template <typename T>
	static void printInt(T t)
	{
		if (std::isnan(t) || t < static_cast<float>(INT_MIN) ||
			t > static_cast<float>(INT_MAX))
			std::cout << "Impossible";
		else
			std::cout << static_cast<int>(t);

		std::cout << "\n";
	}

	template <typename T>
	static void printFloat(T t)
	{
		std::cout << static_cast<float>(t);
		if (static_cast<int>(t) - static_cast<float>(t) == 0)
			std::cout << ".0";
		std::cout << 'f';

		std::cout << "\n";
	}

	template <typename T>
	static void printDouble(T t)
	{
		std::cout << static_cast<double>(t);
		if (static_cast<int>(t) - static_cast<double>(t) == 0)
			std::cout << ".0";

		std::cout << "\n";
	}

  private:
	ScalarConverter();
};

#endif // !SCALARCONVERTER_HPP
