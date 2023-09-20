#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include <FragTrap.hpp>
#include <ScavTrap.hpp>

// clang-format off
class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &inp);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &inp);

    void    WhoamI();
};
// clang-format on

#endif
