
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongDog.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	Animal Zoink;
	Dog Racky;
	Cat Brokje;

	WrongDog Hot;

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "|" << Zoink.get_type() << "| Makes the sound: " << std::endl;
	Zoink.MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "|" << Racky.get_type() << "| Makes the sound: " << std::endl;
	Racky.MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "|" << Brokje.get_type() << "| Makes the sound: " << std::endl;
	Brokje.MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "|" << Hot.get_type() << "| Makes the sound: " << std::endl;
	Hot.MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	return (0);
}
