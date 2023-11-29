
#include <iostream>
#include <string>

#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal()
{
#ifdef MSG
	std::cout << "Called\tWrongAnimal\tConstructor:\tDefault" << std::endl;
#endif
	_type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
#ifdef MSG
	std::cout << "Called\tWrongAnimal\tConstructor:\tCopy" << std::endl;
#endif
	_type = rhs.get_type();
}

WrongAnimal::~WrongAnimal()
{
#ifdef MSG
	std::cout << "Called\tWrongAnimal\tDeconstructor" << std::endl;
#endif
}

WrongAnimal WrongAnimal::operator=(WrongAnimal &rhs)
{
#ifdef MSG
	std::cout << "Called\tWrongAnimal\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &rhs)
		_type = rhs.get_type();
	return (*this);
}

std::string WrongAnimal::get_type() const
{
	return (_type);
}

void WrongAnimal::set_type(std::string type)
{
	_type = type;
}

void WrongAnimal::MakeNoise()
{
	std::cout << "*WrongAnimal Noises" << std::endl;
}
