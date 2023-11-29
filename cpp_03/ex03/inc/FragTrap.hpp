#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include <ClapTrap.hpp>

// clang-format off
class FragTrap : virtual public ClapTrap
{
  protected:
	static const unsigned int base_health = 100;
	static const unsigned int base_energy = 100;
	static const unsigned int base_attack = 30;

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
