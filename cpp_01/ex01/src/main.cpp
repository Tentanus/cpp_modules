#include <string>
#include <iostream>
#include <Zombie.hpp>

#define NBR 10

int main(void) 
{
	Zombie z1("Zomb1");
	Zombie *z2 = new Zombie("Zomb2");

	z1.announce();
	z2->announce();

	delete z2;

	std::cout << "\tHorde is arriving" << std::endl;

	z2 = zombieHorde(NBR, "Horders");

	for (int i = 0; i < NBR; i++)
		z2[i].announce(); 

	std::cout << "\tHorde has passed" << std::endl;

	delete[] z2;
}
