
#include <Weapon.hpp>
#include <HumanB.hpp>

#include <iostream>

HumanB::HumanB(const std::string name)
{
	_name = name;
	_weapon = nullptr;
	std::cout << "Created HumanB: " << _name << "\n\t" << "Weapon: none" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destroyed HumanB: " << _name << std::endl;
}

const Weapon&	HumanB::get_Weapon() const
{
	return(*_weapon);
}

const std::string	HumanB::get_name() const
{
	return(_name);
}

void	HumanB::set_Weapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (!_weapon)
		std::cout << get_name() << " attacks with their Fist" << std::endl;
	else
		std::cout << get_name() << " attacks with their " << get_Weapon().get_Type() << std::endl;
}
