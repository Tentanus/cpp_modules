
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

ScavTrap::ScavTrap(const ScavTrap &inp) : ClapTrap(inp.get_name())
{
#ifdef MSG
	std::cout << "Called\tScavTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << inp.get_name() << " Located at: " << &inp
			  << std::endl;
#endif
	_health = inp.get_health();
	_energy = inp.get_energy();
	_attack = inp.get_attack();
}

ScavTrap::~ScavTrap()
{
#ifdef MSG
	std::cout << "Called\tScavTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

ScavTrap &ScavTrap::operator=(const ScavTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tScavTrap Copy Assignment operator:" << inp._name
			  << "\tLocated at: " << this << std::endl;
#endif
	if (this != &inp)
	{
		_name = inp.get_name();
		_health = inp.get_health();
		_energy = inp.get_energy();
		_attack = inp.get_attack();
	}
	return (*this);
}

void ScavTrap::status() const
{
	std::cout << "Scavtrap\tname:\t\t" << get_name() << "\n\t\thealth:\t\t"
			  << get_health() << "\n\t\tenergy:\t\t" << get_energy()
			  << "\n\t\tattack:\t\t" << get_attack() << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << get_name()
				  << " is too tired and can't attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << get_name() << " attacks " << target << " for "
			  << get_attack() << "." << std::endl;
	_energy--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in mode_gatekeep"
			  << std::endl;
}
