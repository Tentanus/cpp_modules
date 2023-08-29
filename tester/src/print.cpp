#include <iostream>
#include <string>

#include <tester.hpp>

void print_float_bit_reversed(float f0)
{
	int i0;

	i0 = *(int *)&f0;

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

void print_float_bit(float f0)
{
	int i0;

	i0 = *(int *)&f0;

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

#ifdef EXP
	{
		size_t pos = 0;
		float mant = 0;

		std::cout << ((i0 << pos) & 0x80000000 ? "-" : " ") << " ";
		pos++;

		/*
		 * Exponent Bits have some voodoo stuff with them...
		 * 01111111	=	2 ^ 0
		 * 11111111	=	2 ^ 128
		 * 00000000	=	2 ^ -126 (denormalized)
		 * 00000001	=	2 ^ -126
		 */

		for (size_t i = pos; i < 9; i++)
			std::cout << ((i0 << i) & 0x80000000 ? "-" : " ");

		std::cout << " ";

		/* Mantissa Bits
		 * going left to right in the bits thes mantissa works as follows
		 *
		 * 2 ^ -(mbit_position)
		 *
		 * 010	1*2^-1 + 1*2^-2
		 */

		for (size_t i = 9; i < 32; i++)
		{
			if ((i0 << i) & 0x80000000)
				mant += power(2, (8 - i));
		}
		std::cout << mant;

		std::cout << std::endl;
	}
#endif
}
