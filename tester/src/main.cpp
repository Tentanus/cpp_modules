
#include <iostream>
#include <string>
#include <cstdlib>

void	print_float_bit_reversed(float f0)
{
	int	i0;

	i0 = * (int *) &f0;

	for (size_t i = 0; i < sizeof(float) * 8; i++)
	{
		if (i == 23 || i == 31 || i == 32)
			std::cout << " ";
		if (((i0 >> i) & 0x1))
			std::cout << "1";
		else
			std::cout << "0";
	}
	std::cout << "\t" << f0 << std::endl;
}

void	print_float_bit(float f0)
{
	int	i0;

	i0 = * (int *) &f0;

	for (size_t i = 0; i < sizeof(float) * 8; i++)
	{
		if (i == 1 || i == 9)
			std::cout << " ";
		if (((i0 << i) & 0x80000000) >> 31)
			std::cout << "1";
		else
			std::cout << "0";
	}
	std::cout << "\t" << f0 << std::endl;
}

int main()
{

	std::cout << "sizeof float: " << sizeof(float) << "bytes" << std::endl; // 4 bytes

	std::cout << "S EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	std::cout << "\n";
	print_float_bit(0);
	print_float_bit(1);
	std::cout << "\n";
	print_float_bit(0.15625);
	print_float_bit(0.1);
	print_float_bit(0.2);
	print_float_bit(0.3);
	print_float_bit(0.4);
	print_float_bit(0.5);
	return (0);
}
