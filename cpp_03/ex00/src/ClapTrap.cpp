
#include <iostream>

#include <ClapTrap.hpp>

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_ATTACK 5

ClapTrap::ClapTrap()
	: _name("ClapTrap"), _health(CT_HEALTH), _energy(CT_ENERGY),
	  _attack(CT_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tDefault" << std::endl;
#endif
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _health(CT_HEALTH), _energy(CT_ENERGY), _attack(CT_ATTACK)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tname" << std::endl;
#endif
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

ClapTrap::~ClapTrap()
{
#ifdef MSG
	std::cout << "Called\tDestructor" << std::endl;
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
		_health = inp.get_health();
		_energy = inp.get_energy();
		_attack = inp.get_attack();
	}
	return (*this);
}

const std::string ClapTrap::get_name() const
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
	std::cout << "Claptrap\tname:\t\t" << get_name() << "\n\t\thealth:\t\t"
			  << get_health() << "\n\t\tenergy:\t\t" << get_energy()
			  << "\n\t\tattack:\t\t" << get_attack() << std::endl;
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health == 0)
	{
		std::cout << "ClapTrap " << get_name() << " is allready dead."
				  << std::endl;
		return;
	}
	else if (_health <= amount)
	{
		std::cout << "ClapTrap " << get_name() << " took " << get_health()
				  << " points of damage and died." << std::endl;
		_health = 0;
		return;
	}
	std::cout << "ClapTrap " << get_name() << " took " << amount
			  << " points of damage." << std::endl;
	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << get_name()
				  << " is too tired and can't repair." << std::endl;
		return;
	}
	else if (_health == 0)
	{
		std::cout << "ClapTrap " << get_name() << " is allready dead."
				  << std::endl;
		return;
	}
	std::cout << "ClapTrap " << get_name() << " was repaired for " << amount
			  << " HP." << std::endl;
	_health += amount;
	_energy--;
}
