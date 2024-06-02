
#include "Swap.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = \t" << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = \t" << ::max(a, b) << std::endl;

	std::string c = "str_c";
	std::string d = "str_d";

	std::cout << "c = \"" << c << "\", d = \"" << d << "\"" << std::endl;
	::swap(c, d);
	std::cout << "c = \"" << c << "\", d = \"" << d << "\"" << std::endl;

	std::cout << "min( c, d ) = \t" << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = \t" << ::max(c, d) << std::endl;

	/*
	 *	::swap(c, a);
	 *
	 *	std::cout << "c = " << c << ", a = " << a << std::endl;
	 *	std::cout << "min( c, d ) = " << ::min(c, a) << std::endl;
	 *	std::cout << "max( c, d ) = " << ::max(c, a) << std::endl;
	 *	return (0);
	 */
}
