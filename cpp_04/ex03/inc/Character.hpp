#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>

#define CHARACTERSLOT_MAX 4

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria *_slots[CHARACTERSLOT_MAX];

  public:
	Character(const std::string name);
	Character(const Character &rhs);
	virtual ~Character();
	Character &operator=(const Character &rhs);

	std::string const &getName() const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // !CHARACTER_HPP
