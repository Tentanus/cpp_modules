#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include <FragTrap.hpp>
#include <ScavTrap.hpp>

// clang-format off
class DiamondTrap : protected ScavTrap, protected FragTrap
{
  public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &inp);
	DiamondTrap(std::string name);
	DiamondTrap &operator=(const DiamondTrap &inp);
	~DiamondTrap();

    void    WhoamI();
};
// clang-format on

#endif
