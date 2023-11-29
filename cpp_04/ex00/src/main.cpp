
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongDog.hpp>

int main()
{
	Dog Racky;
	WrongDog Hot;
	Cat Robby;

	std::cout << Racky.get_type() << " Makes the sound: " << std::endl;
	Racky.MakeNoise();

	std::cout << Hot.get_type() << " Makes the sound: " << std::endl;
	Hot.MakeNoise();

	std::cout << Robby.get_type() << " Makes the sound: " << std::endl;
	Robby.MakeNoise();

	return (0);
}
