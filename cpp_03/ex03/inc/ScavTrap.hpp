#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

// clang-format off
class ScavTrap : virtual public ClapTrap
{
  protected:
	static const unsigned int base_health = 100;
	static const unsigned int base_energy = 50;
	static const unsigned int base_attack = 20;

  public:
	ScavTrap();
	ScavTrap(const ScavTrap &inp);
	ScavTrap(const std::string name);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &inp);

	void	attack(const std::string &target);
	void	guardGate();
};
// clang-format on

#endif
