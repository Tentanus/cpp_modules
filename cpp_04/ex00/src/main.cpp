
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongDog.hpp>

int main()
{
	Animal Zoink;
	Dog Racky;
	Cat Brokje;

	WrongDog Hot;

	std::cout << Zoink.get_type() << " Makes the sound: " << std::endl;
	Zoink.MakeNoise();

	std::cout << Racky.get_type() << " Makes the sound: " << std::endl;
	Racky.MakeNoise();

	std::cout << Brokje.get_type() << " Makes the sound: " << std::endl;
	Brokje.MakeNoise();

	std::cout << Hot.get_type() << " Makes the sound: " << std::endl;
	Hot.MakeNoise();

	return (0);
}
