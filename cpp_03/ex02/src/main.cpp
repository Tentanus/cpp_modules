
#include <iostream>

#include <FragTrap.hpp>
#include <ScavTrap.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	FragTrap FT_1("Henk");
	ScavTrap ST_1("Jaap");

	std::cout << "\n";

	FT_1.attack("Jaap");
	ST_1.takeDamage(FT_1.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	FT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	FT_1.attack("Jaap");
	ST_1.takeDamage(FT_1.get_attack());
	FT_1.attack("Jaap");
	ST_1.takeDamage(FT_1.get_attack());
	FT_1.attack("Jaap");
	ST_1.takeDamage(FT_1.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	FT_1.status();
	std::cout << "\n";
	ST_1.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	ST_1.guardGate();
	FT_1.highFivesGuys();

	std::cout << "\n";

	//	FT_1.guardGate();
	//	ST_1.highFivesGuys();

	return (0);
}
