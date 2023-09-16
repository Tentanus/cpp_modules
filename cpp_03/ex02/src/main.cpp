
#include "FragTrap.hpp"
#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main()
{
	ClapTrap CT_1("Henk");
	ScavTrap ST_1("Jan");
	FragTrap FT_1("Piet");

	CT_1.attack("Jan");
	CT_1.attack("Piet");
	ST_1.takeDamage(CT_1.get_attack());
	FT_1.takeDamage(CT_1.get_attack());

	std::cout << "\n";
	std::cout << "ClapTrap " << CT_1.get_name() << " has " << CT_1.get_health()
			  << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;
	std::cout << "FragTrap " << FT_1.get_name() << " has " << FT_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.beRepaired(2);
	FT_1.beRepaired(2);

	std::cout << "\n";
	std::cout << "ClapTrap " << CT_1.get_name() << " has " << CT_1.get_health()
			  << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;
	std::cout << "FragTrap " << FT_1.get_name() << " has " << FT_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.attack("Henk");
	CT_1.takeDamage(ST_1.get_attack());
	FT_1.attack("Jan");
	ST_1.takeDamage(FT_1.get_attack());

	std::cout << "\n";
	std::cout << "ClapTrap " << CT_1.get_name() << " has " << CT_1.get_health()
			  << " HP." << std::endl;
	std::cout << "ScavTrap " << ST_1.get_name() << " has " << ST_1.get_health()
			  << " HP.\n"
			  << std::endl;
	std::cout << "FragTrap " << FT_1.get_name() << " has " << FT_1.get_health()
			  << " HP.\n"
			  << std::endl;

	ST_1.guardGate();
	std::cout << "\n";
	FT_1.highFivesGuys();
	return (0);
}
