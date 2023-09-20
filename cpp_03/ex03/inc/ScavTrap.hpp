#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

#define ST_HEALTH 100
#define ST_ENERGY 50
#define ST_ATTACK 20

// clang-format off
class ScavTrap : public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(const ScavTrap &inp);
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &inp);

	void	guardGate();
};
// clang-format on

#endif
