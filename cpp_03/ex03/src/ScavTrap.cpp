
#include <iostream>

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = ScavTrap::base_health;
	_energy = ScavTrap::base_energy;
	_attack = ScavTrap::base_attack;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = ScavTrap::base_health;
	_energy = ScavTrap::base_energy;
	_attack = ScavTrap::base_attack;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs.get_name())
{
#ifdef MSG
	std::cout << "Called\tScavTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << rhs.get_name() << " Located at: " << &rhs
			  << std::endl;
#endif
	_health = rhs.get_health();
	_energy = rhs.get_energy();
	_attack = rhs.get_attack();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Copy Assignment operator:" << rhs._name
			  << "\tLocated at: " << this << std::endl;
#endif
	if (this != &rhs)
	{
		_name = rhs.get_name();
		_health = rhs.get_health();
		_energy = rhs.get_energy();
		_attack = rhs.get_attack();
	}
	return (*this);
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
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << get_name()
				  << " is too tired and can't attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
	_energy--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
