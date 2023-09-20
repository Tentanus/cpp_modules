
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>

int main()
{
	Dog Racky;
	Cat Minouche;

	std::cout << Racky.get_type() << std::endl;
	std::cout << Minouche.get_type() << std::endl;

	return (0);
}
