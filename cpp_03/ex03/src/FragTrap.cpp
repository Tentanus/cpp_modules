
#include <iostream>

#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
#ifdef MSG
	std::cout << "Called\tFragTrap Constructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FragTrap::base_health;
	_energy = FragTrap::base_energy;
	_attack = FragTrap::base_attack;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
#ifdef MSG
	std::cout << "Called\tFragTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FragTrap::base_health;
	_energy = FragTrap::base_energy;
	_attack = FragTrap::base_attack;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs.get_name())
{
#ifdef MSG
	std::cout << "Called\tFragTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << rhs.get_name() << " Located at: " << &rhs
			  << std::endl;
#endif
	_health = rhs.get_health();
	_energy = rhs.get_energy();
	_attack = rhs.get_attack();
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
#ifdef MSG
	std::cout << "Called\tFragTrap Copy Assignment operator:" << rhs._name
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
