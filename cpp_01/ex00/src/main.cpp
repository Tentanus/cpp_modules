#include <string>
#include <Zombie.hpp>

int main(void) 
{
	Zombie z1("Zomb1");
	Zombie *z2 = new Zombie("Zomb2");
	Zombie *z3 = newZombie("Zomb3");

	z1.announce();
	z2->announce();
	z3->announce();

	randomChump("Zomb4");

	delete z2;
	delete z3;
}
