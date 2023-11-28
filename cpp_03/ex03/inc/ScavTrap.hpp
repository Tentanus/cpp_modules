#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

#define ST_HEALTH 50
#define ST_ENERGY 50
#define ST_ATTACK 50

// clang-format off
class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(const ScavTrap &inp);
	ScavTrap(const std::string name);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &inp);

	void	guardGate();
};
// clang-format on

#endif
