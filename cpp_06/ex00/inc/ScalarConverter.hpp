#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	virtual ScalarConverter &operator=(const ScalarConverter &rhs) = 0;
	virtual ~ScalarConverter() = 0;

	static void convert(const std::string input);

  private:
	static void printEmpty(void);
};

#endif // !SCALARCONVERTER_HPP
