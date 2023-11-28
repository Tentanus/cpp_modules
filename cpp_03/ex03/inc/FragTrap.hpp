#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

#define FT_HEALTH 80
#define FT_ENERGY 80
#define FT_ATTACK 80

// clang-format off
class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const FragTrap &inp);
	FragTrap(const std::string name);
	~FragTrap();

	FragTrap &operator=(const FragTrap &inp);

	void	highFivesGuys(void);
};
// clang-format on

#endif
