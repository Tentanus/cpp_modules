
#include <cstdlib>
#include <iostream>
#include <string>

#include <tester.hpp>

int main(int argc, char *argv[])
{

	std::cout << "sizeof float: " << sizeof(float) << "bytes"
			  << std::endl; // 4 bytes

	std::cout << "\nS EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM\n" << std::endl;

	for (int i = 1; i < argc; i++)
	{
		const std::string str(argv[i]);
		float val = std::stof(str, 0);
		print_float_bit(val);
		if ((i % 5) == 0)
			std::cout << "\nS EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM\n" << std::endl;
	}

	return (0);
}
