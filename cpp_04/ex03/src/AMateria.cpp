
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
#ifdef MSG
	std::cout << "Called\tAMateria\tConstructor:\tNamed" << std::endl;
#endif
}

AMateria::AMateria(const AMateria &rhs) : _type(rhs.getType())
{
#ifdef MSG
	std::cout << "Called\tAMateria\tConstructor:\tCopy" << std::endl;
#endif
}

AMateria::~AMateria()
{
#ifdef MSG
	std::cout << "Called\tAMateria\tDeconstructor" << std::endl;
#endif
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
#ifdef MSG
	std::cout << "Called\tAMateria\tCopy Assignment operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_type = rhs.getType();
	return (*this);
}

const std::string &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << " * searches for some Materia to use, but it failed * "
			  << std::endl;
}
