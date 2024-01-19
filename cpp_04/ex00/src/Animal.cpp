
#include <iostream>
#include <string>

#include <Animal.hpp>

Animal::Animal()
{
#ifdef MSG
	std::cout << "Called\tAnimal\tConstructor:\tDefault" << std::endl;
#endif
	_type = "";
}

Animal::Animal(const Animal &rhs)
{
#ifdef MSG
	std::cout << "Called\tAnimal\tConstructor:\tCopy" << std::endl;
#endif
	_type = rhs.get_type();
}

Animal::~Animal()
{
#ifdef MSG
	std::cout << "Called\tAnimal\tDeconstructor" << std::endl;
#endif
}

Animal Animal::operator=(Animal &rhs)
{
#ifdef MSG
	std::cout << "Called\tAnimal\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &rhs)
		_type = rhs.get_type();
	return (*this);
}

std::string Animal::get_type() const
{
	return (_type);
}

void Animal::set_type(std::string type)
{
	_type = type;
}

void Animal::MakeNoise() const
{
	std::cout << " * An uncanny gurgling noise * " << std::endl;
}
