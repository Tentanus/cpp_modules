
#include <iostream>

#include <ClapTrap.hpp>

ClapTrap::ClapTrap() : _name("ClapTrap")
{
#ifdef MSG
	std::cout << "Called\tClapTrap Constructor:\tDefault\t" << _name
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = CT_HEALTH;
	_energy = CT_ENERGY;
	_attack = CT_ATTACK;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tClapTrap Constructor:\tname\t" << _name
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = CT_HEALTH;
	_energy = CT_ENERGY;
	_attack = CT_ATTACK;
}

ClapTrap::ClapTrap(std::string name, unsigned int health, unsigned int energy,
				   unsigned int attack)
	: _name(name)
{
#ifdef MSG
	std::cout << "Called\tClapTrap Constructor:\tconfig\t" << _name
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = health;
	_energy = energy;
	_attack = attack;
}

ClapTrap::~ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tClapTrap Destructor:\tDefault " << _name
			  << "\tLocated at: " << this << std::endl;
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
	std::cout << get_name() << " attacks " << target << " for " << get_attack()
			  << "." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _health)
	{
		std::cout << get_name() << " took too much damage and died."
				  << std::endl;
		_health = 0;
		return;
	}
	std::cout << get_name() << " took " << amount << " points of damage."
			  << std::endl;

	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << get_name() << " was repaired for " << amount << " HP."
			  << std::endl;

	_health += amount;
}
