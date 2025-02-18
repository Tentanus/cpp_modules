#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return (1);
	}
	RPN rpn;
	std::string str(argv[1]);
	try
	{
		for (size_t i = 0; i < str.length(); i++)
		{
#ifdef SHOW
		if (str[i] != ' ')
			std::cout << "str[i]: " << str[i] << "\t";
#endif
			if (str[i] == ' ')
				continue;
			else if (str[i] == '-')
				rpn.subtract();
			else if (str[i] == '*')
				rpn.multiply();
			else if (str[i] == '/')
				rpn.divide();
			else if (str[i] == '+')
				rpn.add();
			else
				rpn.push(str[i]);
#ifdef SHOW
			rpn.print();
#endif
		}
		std::cout << rpn.getTop() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
