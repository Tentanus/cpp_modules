#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_ATTACK 5

class ClapTrap
{
  private:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attack;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &inp);
	ClapTrap &operator=(const ClapTrap &inp);
	~ClapTrap();

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
