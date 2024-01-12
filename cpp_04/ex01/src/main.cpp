
#include <iostream>
#include <string>

#include <Cat.hpp>
#include <Dog.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	{
		Dog *Brok = new Dog;

		Brok->AddIdea("OMG I'm in the park!!");
		Brok->AddIdea("OMG I'm in the park!!");
		Brok->AddIdea("OMG I'm in the park!!");
		for (size_t i = 0; i < 3; i++)
		{
			Brok->AddIdea("OMG My boss is trhowing the ball!!");
			Brok->AddIdea("Get the ball!");
			Brok->AddIdea("Bring ball back to boss!");
		}
		for (int i = -1; i < 15; i++)
			std::cout << "Thought[" << i << "] : " << Brok->readBrain(i)
					  << std::endl;
	}
	std::cout << "\n\n" << MSG_BORDER << "\n" << std::endl;
	{
		Animal *playpen[10];

		for (size_t i = 0; i < 10; i += 2)
		{
			playpen[i] = new Cat;
			playpen[i + 1] = new Dog;
		}

		for (size_t i = 0; i < 10; i++)
			playpen[i]->MakeNoise();

		for (size_t i = 0; i < 10; i++)
			delete playpen[i];
	}

	return (0);
}
