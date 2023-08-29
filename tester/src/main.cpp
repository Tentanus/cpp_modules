
#include <cstdlib>
#include <iostream>
#include <string>

#include <tester.hpp>

float power(int base, int exp)
{
	float res = 1;
	std::cout << base << " " << exp << "\n";

	if (exp == 0)
		return (0);
	if (exp > 0)
	{
		for (size_t i = 1; i <= (size_t)(exp); i++)
			res *= base;
		return (res);
	}
	for (size_t i = 1; i <= (size_t)-exp; i++)
		res /= base;
	return (res);
}

int main(int argc, char *argv[])
{

	std::cout << "sizeof float: " << sizeof(float) << "bytes"
			  << std::endl; // 4 bytes

	std::cout << "\n";

	for (int i = 1; i < argc; i++)
	{
		const std::string str(argv[i]);
		float val = std::stof(str, 0);
		print_float_bit(val);
	}

	return (0);
}
