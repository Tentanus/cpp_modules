
#include "Ice.hpp"
#include "ICharacter.hpp"

#include <string>

Ice::Ice() : AMateria("ice")
{
#ifdef MSG
	std::cout << "Called\tIce\tConstructor:\tNamed" << std::endl;
#endif
}

Ice::Ice(const Ice &rhs) : AMateria(rhs.getType())
{
#ifdef MSG
	std::cout << "Called\tIce\tConstructor:\tCopy" << std::endl;
#endif
}

Ice::~Ice()
{
#ifdef MSG
	std::cout << "Called\tIce\tDeconstructor" << std::endl;
#endif
}

Ice &Ice::operator=(const Ice &rhs)
{
#ifdef MSG
	std::cout << "Called\tIce\tCopy Assignment operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_type = rhs.getType();
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << " * shoots an ice bolt at " << target.getName() << " * "
			  << std::endl;
}
