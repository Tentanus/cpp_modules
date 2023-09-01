
#include <Fixed.hpp>
#include <iostream>

int main()
{
	Fixed a;

	Fixed b(2034.34f);
	Fixed const c(0xFF);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "\nConverts\n\n";

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\nConverts\n\n";

	std::cout << "a is\t" << a.toInt() << " as integer\t\t" << a.toFloat()
			  << " as a float" << std::endl;
	std::cout << "b is\t" << b.toInt() << " as integer\t\t" << b.toFloat()
			  << " as a float" << std::endl;
	std::cout << "c is\t" << c.toInt() << " as integer\t\t" << c.toFloat()
			  << " as a float" << std::endl;
	std::cout << "d is\t" << d.toInt() << " as integer\t\t" << d.toFloat()
			  << " as a float\n"
			  << std::endl;

	return 0;
}
