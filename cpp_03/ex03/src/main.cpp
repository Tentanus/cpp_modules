
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

#define BORDERMESSAGE                                                          \
	"=----------------------------------------------------------="
int main()
{

	DiamondTrap DT("Sjaak");
	ScavTrap ST("Kees");

	std::cout << BORDERMESSAGE << std::endl;
	ST.status();

	std::cout << BORDERMESSAGE << "\n" << std::endl;

	std::cout << "\n";

	std::cout << BORDERMESSAGE << std::endl;
	std::cout << BORDERMESSAGE << "\n" << std::endl;

	std::cout << "\n";

	std::cout << BORDERMESSAGE << std::endl;
	return (0);
}
