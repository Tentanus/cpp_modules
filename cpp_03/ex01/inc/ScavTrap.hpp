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
	ScavTrap(std::string name);
	~ScavTrap();

	std::string		get_name();
	unsigned int	get_health();
	unsigned int	get_energy();
	unsigned int	get_attack();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	guardGate();
};
// clang-format on

#endif
