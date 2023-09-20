
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>

int main()
{
	Dog Racky;
	Cat Minouche;

	std::cout << Racky.get_type() << " Makes the sound: " << std::endl;
	Racky.MakeNoise();

	std::cout << Minouche.get_type() << " Makes the sound: " << std::endl;
	Minouche.MakeNoise();

	return (0);
}
