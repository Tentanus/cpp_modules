#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
	const std::string _name;
	Materia _slots[4];

  public:
	Character(const std::string name);
	Character(const Character &rhs);
	~Character();
	Character &operator=(const Character &rhs);

	std::string const &getName() const;

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // !CHARACTER_HPP