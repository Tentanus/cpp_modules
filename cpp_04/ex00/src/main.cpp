
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongDog.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	{
		Animal *Zoink = new Animal();
		Animal *Racky = new Dog();
		Animal *Brokje = new Cat();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		std::cout << "|" << Zoink->get_type()
				  << "| Makes the sound: " << std::endl;
		Zoink->MakeNoise();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		std::cout << "|" << Racky->get_type()
				  << "| Makes the sound: " << std::endl;
		Racky->MakeNoise();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		std::cout << "|" << Brokje->get_type()
				  << "| Makes the sound: " << std::endl;
		Brokje->MakeNoise();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		delete Zoink;
		delete Racky;
		delete Brokje;

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;
	}
	{
		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		WrongDog *Wdog = new WrongDog();
		WrongAnimal *Wanimal = new WrongDog();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		std::cout << "|" << Wdog->get_type()
				  << "| Makes the sound: " << std::endl;
		Wdog->MakeNoise();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		std::cout << "|" << Wanimal->get_type()
				  << "| Makes the sound: " << std::endl;
		Wanimal->MakeNoise();

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

		delete Wdog;
		delete Wanimal;

		std::cout << "\n" << MSG_BORDER << "\n" << std::endl;
	}

	return (0);
}
