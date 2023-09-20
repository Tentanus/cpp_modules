#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

#define FT_HEALTH 100
#define FT_ENERGY 100
#define FT_ATTACK 30

// clang-format off
class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &inp);
	~FragTrap();

	FragTrap &operator=(const FragTrap &inp);

	void	highFivesGuys(void);
};
// clang-format on

#endif
