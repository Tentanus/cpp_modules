
#include <iostream>

#include <ClapTrap.hpp>

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_ATTACK 5

ClapTrap::ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tDefault" << std::endl;
#endif
	_health = CT_HEALTH;
	_energy = CT_ENERGY;
	_attack = CT_ATTACK;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tname" << std::endl;
#endif
	_health = CT_HEALTH;
	_energy = CT_ENERGY;
	_attack = CT_ATTACK;
}

ClapTrap::ClapTrap(ClapTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tCopy Constructor:" << inp._name << std::endl;
#endif
	_name = inp.get_name();
	_health = inp.get_health();
	_energy = inp.get_energy();
	_attack = inp.get_attack();
}

ClapTrap::~ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tDestructor:\tDefault" << std::endl;
#endif
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

void ClapTrap::status() const
{
	std::cout << "\n"
			  << get_name() << " has following stats:\n"
			  << "health:\t" << get_health() << "\nenergy:\t" << get_energy()
			  << "\nattack:\t" << get_attack() << "\n"
			  << std::endl;
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
