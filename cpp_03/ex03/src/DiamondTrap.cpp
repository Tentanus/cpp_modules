
#include <iostream>

#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap() : ScavTrap("DiamondTrap_clap_name")
{
	ScavTrap::_health = FT_HEALTH;
	ScavTrap::_energy = ST_ENERGY;
	ScavTrap::_attack = FT_ATTACK;
#ifdef MSG
	std::cout << "Called\tDiamTrap Constructor:\tname\t" << get_name()
			  << "\tLocated at: " << this << std::endl;
#endif
}

DiamondTrap::DiamondTrap(const std::string name) : ScavTrap(name + "_clap_name")
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

DiamondTrap::~DiamondTrap()
{
#ifdef MSG
	std::cout << "Called\tDiamTrap Destructor:\tDefault\t"
			  << ScavTrap::get_name() << "\tLocated at: " << this << std::endl;
#endif
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
