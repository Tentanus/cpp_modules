

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	//  This will not Compile due to AAnimal being an Abstract Class
	//	AAnimal *Zoink = new AAnimal;

	AAnimal *Brutus = new Dog;
	AAnimal *Boris = new Cat;

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "A dog goes: " << std::endl;
	Brutus->MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	std::cout << "A cat goes: " << std::endl;
	Boris->MakeNoise();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	delete Brutus;
	delete Boris;
	return (0);
}
