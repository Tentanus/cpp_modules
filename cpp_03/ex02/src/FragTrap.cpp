
#include <iostream>

#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
#ifdef MSG
	std::cout << "Called\tFragTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FT_HEALTH;
	_energy = FT_ENERGY;
	_attack = FT_ATTACK;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
#ifdef MSG
	std::cout << "Called\tFragTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FT_HEALTH;
	_energy = FT_ENERGY;
	_attack = FT_ATTACK;
}

FragTrap::~FragTrap()
{
#ifdef MSG
	std::cout << "Called\tFragTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
}

void FragTrap::guardGate()
{
	std::cout << "FragTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
