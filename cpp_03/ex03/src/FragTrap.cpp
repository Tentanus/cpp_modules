
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

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
#ifdef MSG
	std::cout << "Called\tFragTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FT_HEALTH;
	_energy = FT_ENERGY;
	_attack = FT_ATTACK;
}

FragTrap::FragTrap(const FragTrap &inp) : ClapTrap(inp.get_name())
{
#ifdef MSG
	std::cout << "Called\tFragTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << inp.get_name() << " Located at: " << &inp
			  << std::endl;
#endif
	_health = inp.get_health();
	_energy = inp.get_energy();
	_attack = inp.get_attack();
}

FragTrap::~FragTrap()
{
#ifdef MSG
	std::cout << "Called\tFragTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

FragTrap &FragTrap::operator=(const FragTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tFragTrap Copy Assignment operator:" << inp._name
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << get_name() << " wants a highfives" << std::endl;
}
