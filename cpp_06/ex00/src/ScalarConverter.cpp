
#include "ScalarConverter.hpp"
#include <cctype>

//-------------------Static Fucntion-------------------//

static bool stris(std::string str, int (*f)(int))
{
	for (std::string::iterator i = str.begin(); i < str.end(); i++)
		if (!f(*i))
			return (false);
	return (true);
}

static type_id detectID(std::string str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return (DOUBLE);
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return (FLOAT);
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	if (!str.empty() && stris(str, std::isdigit) == true)
		return (INT);
	if (str.find('.') == std::string::npos || str.find('.') != str.rfind('.'))
		return (IMPOSSIBLE);
	size_t pos = str.find('.');
	if (stris(str.substr(0, pos), std::isdigit) &&
		stris(str.substr(pos + 1, str.length() - pos - 1), std::isdigit))
		return (DOUBLE);
	if (str[str.length() - 1] == 'f' &&
		stris(str.substr(0, pos), std::isdigit) &&
		stris(str.substr(pos + 1, str.length() - pos - 2), std::isdigit))
		return (FLOAT);
	return (IMPOSSIBLE);
}

//-------------------Member Functions-------------------//

void ScalarConverter::printImpossible(void)
{
}

void ScalarConverter::convert(const std::string &str)
{
	type_id id = detectID(str);
	printType(str);
	(void)id;
	/*
	switch (id)
		{
		case CHAR:
			break;
		case INT:
			break;
		case FLOAT:
			break;
		case DOUBLE:
			break;
		case IMPOSSIBLE:
			break;
		default:
			ScalarConverter::printType(str);
			break;
		}
	*/
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
