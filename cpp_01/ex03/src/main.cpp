
#include <string>
#include <iostream>

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

int main() 
{
	{
		std::cout << "Senario 1:\n\n";

		Weapon club = Weapon("Crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.set_Type("Different CLUB");
		bob.attack();
	}

	{
		std::cout << "\nSenario 2:\n\n";

		Weapon club = Weapon("Crude spiked club");
		HumanB jim("Jim");

		jim.attack();
		jim.set_Weapon(club);
		jim.attack();
		club.set_Type("Morning Star");
		jim.attack();
	}

	return (0);
}
