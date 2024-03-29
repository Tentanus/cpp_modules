
#include <ClapTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <iostream>

#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap()
	: ClapTrap("ClapTrap_clap_name"), name("DiamondTrap_clap_name")
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Constructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FragTrap::base_health;
	_energy = ScavTrap::base_energy;
	_attack = FragTrap::base_attack;
}

DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name + "_clap_name"), name(name)
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Constructor:\tname\t" << ScavTrap::get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
	_health = FragTrap::base_health;
	_energy = ScavTrap::base_energy;
	_attack = FragTrap::base_attack;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
	: ClapTrap(rhs.get_name() + "_clap_name"), name(rhs.get_name())
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << rhs.get_name() << " Located at: " << &rhs
			  << std::endl;
#endif
	_health = rhs.get_health();
	_energy = rhs.get_energy();
	_attack = rhs.get_attack();
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Copy Assignment operator:" << rhs._name
			  << "\tLocated at: " << this << std::endl;
#endif
	if (this != &rhs)
	{
		name = rhs.get_name();
		_name = rhs.get_name() + "_clap_name";
		_health = rhs.get_health();
		_energy = rhs.get_energy();
		_attack = rhs.get_attack();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Destructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

void DiamondTrap::WhoamI()
{
	std::cout << "My name is: " << name << "\nClaptrap _name: " << get_name()
			  << std::endl;
}
