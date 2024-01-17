#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_ATTACK 0

class ClapTrap
{
  protected:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attack;

  public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &inp);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &inp);

	const std::string get_name() const;
	unsigned int get_health() const;
	unsigned int get_energy() const;
	unsigned int get_attack() const;

	void status() const;

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
