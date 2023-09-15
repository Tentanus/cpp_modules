
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << get_name() << " wants a highfives" << std::endl;
}
