
#include <iostream>
#include <string>

#include <AAnimal.hpp>

AAnimal::AAnimal()
{
#ifdef MSG
	std::cout << "Called\tAnimal\tConstructor:\tDefault" << std::endl;
#endif
	_type = "";
}

AAnimal::AAnimal(const AAnimal &rhs)
{
#ifdef MSG
	std::cout << "Called\tAnimal\tConstructor:\tCopy" << std::endl;
#endif
	_type = rhs.get_type();
}

AAnimal::~AAnimal()
{
#ifdef MSG
	std::cout << "Called\tAnimal\tDeconstructor" << std::endl;
#endif
}

std::string AAnimal::get_type() const
{
	return (_type);
}

void AAnimal::set_type(std::string type)
{
	_type = type;
}

void AAnimal::MakeNoise()
{
	std::cout << " * An uncanny gurgling noise * " << std::endl;
}
