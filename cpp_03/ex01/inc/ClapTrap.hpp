#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  protected:
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

	std::string get_name() const;
	unsigned int get_health() const;
	unsigned int get_energy() const;
	unsigned int get_attack() const;

	void status() const;

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
