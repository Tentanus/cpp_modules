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

	static const unsigned int base_health = 10;
	static const unsigned int base_energy = 10;
	static const unsigned int base_attack = 0;

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

	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
