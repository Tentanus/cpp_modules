
#include <iostream>
#include <string>

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
