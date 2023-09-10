#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

#define FT_HEALTH 100
#define FT_ENERGY 100
#define FT_ATTACK 30

// clang-format off
class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);};

// clang-format on

#endif
