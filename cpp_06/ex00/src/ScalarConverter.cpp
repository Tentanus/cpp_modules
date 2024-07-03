
#include "ScalarConverter.hpp"
#include <cctype>
#include <string>

//-------------------Static Fucntion-------------------//

static bool stris(std::string str, int (*f)(int))
{
	for (std::string::iterator i = str.begin(); i < str.end(); i++)
		if (!f(*i))
			return (false);
	return (true);
}

static bool isFloat(std::string str)
{
	size_t pos_dot = str.find('.');

	if (stris(str.substr(0, pos_dot), std::isdigit) &&
		stris(str.substr(pos_dot + 1, str.length() - pos_dot - 2),
			  std::isdigit))
		return (true);
	return (false);
}

static type_id detectID(std::string str)
{
	if (str.empty())
		return (IMPOSSIBLE);
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return (DOUBLE);
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return (FLOAT);
	if (str.length() == 1 &&
		(stris(str, std::iscntrl) || stris(str, std::isspace) ||
		 stris(str, std::isgraph)))
		return (CHAR);
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	if (stris(str, std::isdigit) == true)
		return (INT);
	if (str.find('f') == (str.length() - 1))
	{
		str = str.substr(0, str.length() - 1);
		if (isFloat(str))
			return (FLOAT);
	}
	else if (isFloat(str))
		return (DOUBLE);
	return (IMPOSSIBLE);
}

static void printImpossible(void)
{
	std::cout << "Char:\tImpossible\n";
	std::cout << "Int:\tImpossible\n";
	std::cout << "Float:\tImpossible\n";
	std::cout << "Double:\tImpossible\n";
	std::cout << std::flush;
}

template <typename T>
static void printType(T t)
{
	std::cout << "Char:\t";
	ScalarConverter::printChar(t);
	std::cout << "Int:\t";
	ScalarConverter::printInt(t);
	std::cout << "Float:\t";
	ScalarConverter::printFloat(t);
	std::cout << "Double:\t";
	ScalarConverter::printDouble(t);
	std::cout << std::flush;
}

//-------------------Member Functions-------------------//

void ScalarConverter::convert(const std::string str)
{
	type_id id = detectID(str);
	// std::cout << id << "\t" << id_names[id] << "\n" << std::endl;
	switch (id)
	{
	case IMPOSSIBLE:
		printImpossible();
		break;
	case CHAR:
		printType(str[0]);
		break;
	case INT:
		printType(std::stoi(str));
		break;
	case FLOAT:
		printType(std::stof(str));
		break;
	case DOUBLE:
		printType(std::stod(str));
		break;
	default:
		std::cerr << "Error: Unknown type_id" << std::endl;
		break;
	}
}

//-------------------Orthodox Canonical Form-------------------//
//		these are never used since the class is Abstract.

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
