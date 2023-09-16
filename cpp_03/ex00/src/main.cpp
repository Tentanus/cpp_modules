
#include <iostream>

#include <ClapTrap.hpp>

int main()
{
	ClapTrap CT_1("Henk");

	CT_1.attack("Henk");
	CT_1.takeDamage(5);

	CT_1.status();

	CT_1.beRepaired(5);

	CT_1.status();

	return (0);
}
