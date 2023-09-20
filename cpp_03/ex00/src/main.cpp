
#include <iostream>

#include <ClapTrap.hpp>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	ClapTrap CT_1("Henk");
	ClapTrap CT_2;

	CT_2.attack("Henk");
	CT_1.takeDamage(CT_2.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	CT_2.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	CT_2.attack("Henk");
	CT_1.takeDamage(CT_2.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	CT_2.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	CT_2.attack("Henk");
	CT_1.takeDamage(CT_2.get_attack());

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	CT_2.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	CT_2.beRepaired(2);
	CT_1.beRepaired(2);

	std::cout << "\n" << MSG_BORDER << std::endl;
	CT_1.status();
	std::cout << "\n";
	CT_2.status();
	std::cout << MSG_BORDER << "\n" << std::endl;

	return (0);
}
