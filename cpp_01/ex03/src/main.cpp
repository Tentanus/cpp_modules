
#include <string>
#include <iostream>
#include <Weapon>
#include <HumanA>
#include <HumanB>

int main(void) 
{
	{
		Weapon club = Weapon("Crude spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.setType("Club with nails in hammered in");
		bob.attack();
	}
	{
		Weapon club = Weapon("Crude spiked club");

		HumanB jim("jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Club with nails in hammered in");
		jim.attack();
	}

	return (0);
}
