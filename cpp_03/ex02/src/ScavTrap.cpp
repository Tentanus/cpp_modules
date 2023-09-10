
#include <iostream>

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", ST_HEALTH, ST_ENERGY, ST_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, ST_HEALTH, ST_ENERGY, ST_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

ScavTrap::~ScavTrap()
{
#ifdef MSG
	std::cout << "Called\tScavTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
