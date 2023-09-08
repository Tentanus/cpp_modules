#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_ATTACK 5

// clang-format off
class ClapTrap
{
protected:
	const std::string	_name;
	unsigned int		_health;
	unsigned int		_energy;
	unsigned int		_attack;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(	std::string name,
				unsigned int health,
				unsigned int energy,
				unsigned int attack);
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
