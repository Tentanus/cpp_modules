
#include "Swap.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = \n" << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = \n" << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = \n" << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = \n" << ::max(c, d) << std::endl;

	/*
	 *	::swap(c, a);
	 *
	 *	std::cout << "c = " << c << ", a = " << a << std::endl;
	 *	std::cout << "min( c, d ) = " << ::min(c, a) << std::endl;
	 *	std::cout << "max( c, d ) = " << ::max(c, a) << std::endl;
	 *	return (0);
	 */
}
