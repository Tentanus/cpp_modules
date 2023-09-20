
#include <iostream>
#include <string>

#include <Animal.hpp>

Animal::Animal()
{
#ifdef MSG
	std::cout << "Called\tAnimal Constructor:\tDefault\t" << std::endl;
#endif
	_type = "";
}

Animal::Animal(const Animal &inp)
{
#ifdef MSG
	std::cout << "Called\tAnimal Constructor:\tCopy\t" << std::endl;
#endif
	_type = inp.get_type();
}

Animal::~Animal()
{
#ifdef MSG
	std::cout << "Called\tAnimal Deconstructor" << std::endl;
#endif
}

Animal Animal::operator=(Animal &inp)
{
#ifdef MSG
	std::cout << "Called\tAnimal Copy Assignment Operator" << std::endl;
#endif
	if (this != &inp)
		_type = inp.get_type();
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
