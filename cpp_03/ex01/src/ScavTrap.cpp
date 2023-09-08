
#include <iostream>

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", ST_HEALTH, ST_ENERGY, ST_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname" << get_name()
			  << std::endl;
#endif
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, ST_HEALTH, ST_ENERGY, ST_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname" << get_name()
			  << std::endl;
#endif
}

ScavTrap::~ScavTrap()
{
#ifdef MSG
	std::cout << "Called\tScavTrap Destructor:\tDefault " << get_name()
			  << std::endl;
#endif
}

std::string ScavTrap::get_name()
{
	return (_name);
}

unsigned int ScavTrap::get_health()
{
	return (_health);
}

unsigned int ScavTrap::get_energy()
{
	return (_energy);
}

unsigned int ScavTrap::get_attack()
{
	return (_attack);
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount >= _health)
	{
		std::cout << "ScavTrap " << get_name()
				  << " took too much damage and died." << std::endl;
		_health = 0;
		return;
	}
	std::cout << "ScavTrap " << get_name() << " took " << amount
			  << " points of damage." << std::endl;

	_health -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << get_name() << " was repaired for " << amount
			  << " HP." << std::endl;

	_health += amount;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
