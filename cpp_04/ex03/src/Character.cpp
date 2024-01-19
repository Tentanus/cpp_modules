
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string name) : _name(name)
{
#ifdef MSG
	std::cout << "Called\tCharacter\tConstructor:\tNamed" << std::endl;
#endif

	for (size_t idx = 0; idx < CHARACTERSLOT_MAX; idx++)
		_slots[idx] = NULL;
}

Character::Character(const Character &rhs) : _name(rhs.getName())
{
#ifdef MSG
	std::cout << "Called\tCharacter\tConstructor:\tCopy" << std::endl;
#endif

	for (size_t idx = 0; idx < CHARACTERSLOT_MAX; idx++)
		_slots[idx] = rhs._slots[idx];
}

Character::~Character()
{
#ifdef MSG
	std::cout << "Called\tCharacter\tDeconstructor" << std::endl;
#endif

	for (size_t idx = 0; idx < CHARACTERSLOT_MAX; idx++)
		if (_slots[idx])
			delete _slots[idx];
}

Character &Character::operator=(const Character &rhs)
{
#ifdef MSG
	std::cout << "Called\tCharacter\tCopy Assignment operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_name = rhs.getName();
	for (size_t idx = 0; idx < CHARACTERSLOT_MAX; idx++)
		if (_slots[idx])
			_slots[idx] = rhs._slots[idx];

	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << getName() << " can't learn this the VOID Materia."
				  << std::endl;
		return;
	}

	size_t idx = 0;
	while (idx < CHARACTERSLOT_MAX && _slots[idx] != NULL)
		idx++;

	if (idx == CHARACTERSLOT_MAX)
	{
		std::cout << getName()
				  << " has no more slots and the Materia has evaporated."
				  << std::endl;
		delete m;
		return;
	}

	_slots[idx] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= CHARACTERSLOT_MAX)
	{
		std::cout << getName() << " doesn't have this knowledge of Materia."
				  << std::endl;
		return;
	}

	_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= CHARACTERSLOT_MAX || _slots[idx] == NULL)
	{
		std::cout << getName() << " doesn't have this knowledge of Materia."
				  << std::endl;
		return;
	}

	_slots[idx]->use(target);
}
