
#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main()
{
	ClapTrap CT_1("Henk");
	ScavTrap ST_1("Jan");

	CT_1.attack("Jan");
	ST_1.takeDamage(CT_1.get_attack());

	std::cout << "\nClapTrap " << CT_1.get_name() << " has "
			  << CT_1.get_health() << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.beRepaired(2);

	std::cout << "\nClapTrap " << CT_1.get_name() << " has "
			  << CT_1.get_health() << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.attack("Henk");
	CT_1.takeDamage(ST_1.get_attack());

	std::cout << "\nClapTrap " << CT_1.get_name() << " has "
			  << CT_1.get_health() << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.guardGate();
	return (0);
}
