
#include <Fixed.hpp>
#include <iostream>

int main(void)
{
	Fixed a(4);
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(a + 1);

	std::cout << "Comparisons:\n" << std::endl;

	std::cout << "a = " << a << "\nc = " << c << "\n" << std::endl;
	if (a == a)
		std::cout << "a == a" << std::endl;
	if (a != c)
		std::cout << "a != c" << std::endl;
	if (a < c)
		std::cout << "a <  c" << std::endl;
	if (c > a)
		std::cout << "c >  a" << std::endl;
	if (a <= c)
		std::cout << "a <= c" << std::endl;
	if (c >= a)
		std::cout << "c >= a" << std::endl;

	std::cout << "\n\nIterators:\n" << std::endl;

	std::cout << "a:\t" << a << std::endl;
	std::cout << "++a:\t" << ++a << std::endl;
	std::cout << "a:\t" << a << std::endl;
	std::cout << "a++:\t" << a++ << std::endl;
	std::cout << "a:\t" << a << std::endl;

	std::cout << "\n\nOther Operations:\n" << std::endl;
	std::cout << "\na = " << a << "\nc = " << c << "\n" << std::endl;

	std::cout << "a + c =\t" << a + l << std::endl;
	std::cout << "a - c =\t" << a - c << std::endl;
	std::cout << "a * c =\t" << a * c << std::endl;
	std::cout << "a / c =\t" << a / c << std::endl;

	std::cout << "\n\nMinimum / Maximimum:\n" << std::endl;

	std::cout << "max(a,b):\t" << Fixed::max(a, b) << std::endl;
	std::cout << "min(a,b):\t" << Fixed::min(a, b) << std::endl;
}
