
#include <iostream>

#include <DiamondTrap.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	DiamondTrap DT_1("Henk");
	ScavTrap ST_1("Jaap");

	std::cout << "\n";

	DT_1.attack("Jaap");
	ST_1.takeDamage(DT_1.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	DT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	DT_1.attack("Jaap");
	ST_1.takeDamage(DT_1.get_attack());
	DT_1.attack("Jaap");
	ST_1.takeDamage(DT_1.get_attack());
	DT_1.attack("Jaap");
	ST_1.takeDamage(DT_1.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	DT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	ST_1.guardGate();
	DT_1.highFivesGuys();

	std::cout << "\n";

	//	DT_1.guardGate();
	//	ST_1.highFivesGuys();

	return (0);
}
