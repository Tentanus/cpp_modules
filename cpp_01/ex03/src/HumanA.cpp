
#include <Weapon.hpp>
#include <HumanA.hpp>

#include <iostream>

HumanA::HumanA(const std::string& name, const Weapon& weapon)
{
	_name = name;
	_weapon = weapon;
	std::cout << "Created HumanA: " << _name << "\n\t" << "Weapon: " << weapon.get_Type() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destroyed HumanA: " << _name << std::endl;
}

const std::string&	HumanA::get_name() const
{
	return(_name);
}

const Weapon&	HumanA::get_Weapon() const
{
	return(_weapon);
}

void	HumanA::attack()
{
	std::cout << get_name() << " attacks with their " << get_Weapon().get_Type() << std::endl;
}
