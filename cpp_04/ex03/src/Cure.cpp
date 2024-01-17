
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

#include <string>

Cure::Cure() : AMateria("cure")
{
#ifdef MSG
	std::cout << "Called\tCure\tConstructor:\tNamed" << std::endl;
#endif
}

Cure::Cure(const Cure &rhs) : AMateria(rhs.getType())
{
#ifdef MSG
	std::cout << "Called\tCure\tConstructor:\tCopy" << std::endl;
#endif
}

Cure::~Cure()
{
#ifdef MSG
	std::cout << "Called\tCure\tDestructor" << std::endl;
#endif
}

Cure &Cure::operator=(const Cure &rhs)
{
#ifdef MSG
	std::cout << "Called\tCure\tCopy Assignment operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_type = rhs.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << " * heals " << target.getName() << "'s wounds * " << std::endl;
}
