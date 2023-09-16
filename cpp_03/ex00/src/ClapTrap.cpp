
#include <iostream>

#include <ClapTrap.hpp>

ClapTrap::ClapTrap(std::string name) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tname" << std::endl;
#endif
	_health = 10;
	_energy = 10;
	_attack = 5;
}

ClapTrap::ClapTrap(ClapTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tCopy Constructor:" << inp._name << std::endl;
#endif
	if (this != &inp)
	{
		_name = inp.get_name();
		_health = inp.get_health();
		_energy = inp.get_energy();
		_attack = inp.get_attack();
	}
}

ClapTrap &ClapTrap::operator=(const ClapTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tCopy Assignment operator:" << inp._name << std::endl;
#endif
	if (this != &inp)
	{
		_name = inp.get_name();
		_health = inp._health;
		_energy = inp._energy;
		_attack = inp._attack;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tDestructor:\tDefault" << std::endl;
#endif
}

std::string ClapTrap::get_name() const
{
	return (_name);
}

unsigned int ClapTrap::get_health() const
{
	return (_health);
}

unsigned int ClapTrap::get_energy() const
{
	return (_energy);
}

unsigned int ClapTrap::get_attack() const
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
