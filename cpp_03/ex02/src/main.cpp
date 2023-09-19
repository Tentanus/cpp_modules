
#include "FragTrap.hpp"
#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

#define BORDERMESSAGE                                                          \
	"=----------------------------------------------------------="
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

	std::cout << BORDERMESSAGE << std::endl;
	CT_1.status();
	ST_1.status();
	FT_1.status();
	std::cout << BORDERMESSAGE << "\n" << std::endl;

	ST_1.beRepaired(2);
	FT_1.beRepaired(2);
	std::cout << "\n";

	std::cout << BORDERMESSAGE << std::endl;
	CT_1.status();
	ST_1.status();
	FT_1.status();
	std::cout << BORDERMESSAGE << "\n" << std::endl;

	ST_1.attack("Henk");
	CT_1.takeDamage(ST_1.get_attack());
	FT_1.attack("Jan");
	ST_1.takeDamage(FT_1.get_attack());
	std::cout << "\n";

	std::cout << BORDERMESSAGE << std::endl;
	CT_1.status();
	ST_1.status();
	FT_1.status();
	std::cout << BORDERMESSAGE << "\n" << std::endl;

	ST_1.guardGate();
	std::cout << "\n";
	FT_1.highFivesGuys();
	return (0);
}
