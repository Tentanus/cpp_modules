
#include <iostream>

#include <ScavTrap.hpp>

ClapTrap::ClapTrap(std::string name) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tname" << std::endl;
#endif
	_health = 10;
	_energy = 10;
	_attack = 5;
}

ClapTrap::~ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tDestructor:\tDefault" << std::endl;
#endif
}

std::string ClapTrap::get_name()
{
	return (_name);
}

unsigned int ClapTrap::get_health()
{
	return (_health);
}

unsigned int ClapTrap::get_energy()
{
	return (_energy);
}

unsigned int ClapTrap::get_attack()
{
	return (_attack);
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << get_name() << " took " << amount
			  << " points of damage." << std::endl;

	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << get_name() << " was repaired for " << amount
			  << " HP." << std::endl;

	_health += amount;
}
