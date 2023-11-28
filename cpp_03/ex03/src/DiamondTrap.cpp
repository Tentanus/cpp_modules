
#include <ClapTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <iostream>

#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name")
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Constructor:\tDefault\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Constructor:\tname\t" << ScavTrap::get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

DiamondTrap::DiamondTrap(const DiamondTrap &inp)
	: ScavTrap(inp.ScavTrap::get_name() + "_clap_name")
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Copy Constructor on:\t" << this
			  << "\nCopied from: " << inp.ScavTrap::get_name()
			  << " Located at: " << &inp << std::endl;
#endif
	ScavTrap::_health = inp.ScavTrap::get_health();
	ScavTrap::_energy = inp.ScavTrap::get_energy();
	ScavTrap::_attack = inp.ScavTrap::get_attack();
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &inp)
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Copy Assignment operator:"
			  << inp.ScavTrap::_name << "\tLocated at: " << this << std::endl;
#endif
	if (this != &inp)
	{
		ScavTrap::_name = inp.ScavTrap::get_name() + "_clap_name";
		ScavTrap::_health = inp.ScavTrap::get_health();
		ScavTrap::_energy = inp.ScavTrap::get_energy();
		ScavTrap::_attack = inp.ScavTrap::get_attack();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Destructor:\tDefault\t"
			  << ScavTrap::get_name() << "\tLocated at: " << this << std::endl;
#endif
}
