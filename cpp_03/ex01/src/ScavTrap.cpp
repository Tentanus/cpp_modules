
#include "ClapTrap.hpp"
#include <iostream>

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = ST_HEALTH;
	_energy = ST_ENERGY;
	_attack = ST_ATTACK;
}

ScavTrap::ScavTrap(const ScavTrap &inp) : ClapTrap(inp.get_name())
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = inp.get_health();
	_energy = inp.get_energy();
	_attack = inp.get_attack();
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = ST_HEALTH;
	_energy = ST_ENERGY;
	_attack = ST_ATTACK;
}

ScavTrap::~ScavTrap()
{
#ifdef MSG
	std::cout << "Called\tScavTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
