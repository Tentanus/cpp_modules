
#include <string>
#include <iostream>

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

int main() 
{
	{
		Weapon club = Weapon("Crude spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.set_Type("Club with nails in hammered in");
		bob.attack();
	}
	{
		Weapon club = Weapon("Crude spiked club");

		HumanB jim("jim");
		jim.set_Weapon(club);
		jim.attack();
		club.set_Type("Club with nails in hammered in");
		jim.attack();
	}

	return (0);
}
