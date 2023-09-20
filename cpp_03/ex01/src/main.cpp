
#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	ClapTrap CT_1("Henk");
	ScavTrap ST_1("Jaap");

	std::cout << "\n";

	ST_1.attack("Henk");
	CT_1.takeDamage(ST_1.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	ST_1.beRepaired(2);
	CT_1.beRepaired(2);

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	return (0);
}
