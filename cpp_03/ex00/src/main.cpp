
#include <iostream>

#include <ClapTrap.hpp>

int main()
{
	ClapTrap CT_1("Henk");

	CT_1.attack("Henk");
	CT_1.takeDamage(5);

	std::cout << "ClapTrap " << CT_1.get_name() << " has healt of "
			  << CT_1.get_health() << " HP." << std::endl;

	CT_1.beRepaired(5);

	std::cout << "ClapTrap " << CT_1.get_name() << " has healt of "
			  << CT_1.get_health() << " HP." << std::endl;

	return (0);
}
