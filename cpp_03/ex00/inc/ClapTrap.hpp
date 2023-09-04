#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// clang-format off
class ClapTrap
{
  private:
	const std::string	_name;
	unsigned int		_health;
	unsigned int		_energy;
	unsigned int		_attack;

  public:
	ClapTrap(std::string name);
	~ClapTrap();

	std::string		get_name();
	unsigned int	get_health();
	unsigned int	get_energy();
	unsigned int	get_attack();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
// clang-format on

#endif
