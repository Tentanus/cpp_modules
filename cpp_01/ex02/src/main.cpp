
#include <string>
#include <iostream>

int main(void) 
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "ADRESSES:\n";
	std::cout << "\tstring variable \t" << &string << "\n";
	std::cout << "\tpointer variable\t" << &stringPTR << "\n";
	std::cout << "\trefrence variable\t" << &stringREF << "\n";

	std::cout << "\nVALUES:\n";
	std::cout << "\tstring variable \t" << string << "\n";
	std::cout << "\tpointer variable\t" << *stringPTR << "\n";
	std::cout << "\trefrence variable\t" << stringREF << std::endl;
	return (0);
}
