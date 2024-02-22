
#include "ScalarConverter.hpp"
#include <cctype>

void ScalarConverter::convert(const std::string &str)
{
	type_id str_id = detectID(str);
}

//-------------------Private Member Fucntion-------------------//

ScalarConverter::type_id ScalarConverter::detectID(std::string str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")	
		return (DOUBLE);
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")	
		return (FLOAT);
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	if (std::isdigit(str.c_str()))
} 

//-------------------Orthodox Canonical Form-------------------//

ScalarConverter::ScalarConverter()
{
#ifdef MSG
	std::cout << "Called\tScalarConverter\tConstructor:\tDefault" << std::endl;
#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
#ifdef MSG
	std::cout << "Called\tScalarConverter\tConstructor:\tCopy" << std::endl;
#endif
	(void)rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
#ifdef MSG
	std::cout << "Called\tScalarConverter\tCopy Assignment operator"
			  << std::endl;
#endif

	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
#ifdef MSG
	std::cout << "Called\tScalarConverter\tDeconstructor" << std::endl;
#endif
}
