
#include <iostream>
#include <string>

#include <Dog.hpp>

Dog::Dog() : Animal()
{
#ifdef MSG
	std::cout << "Called\tDog\tConstructor:\tDefault" << std::endl;
#endif
	set_type("Dog");
}

Dog::Dog(Dog &rhs) : Animal()
{
#ifdef MSG
	std::cout << "Called\tDog\tConstructor\tCopy" << std::endl;
#endif
	set_type(rhs.get_type());
}

Dog::~Dog()
{
#ifdef MSG
	std::cout << "Called\tDog\tDeconstructor" << std::endl;
#endif
}

Dog Dog::operator=(const Dog &rhs)
{
#ifdef MSG
	std::cout << "Called\tDog\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &rhs)
		_type = rhs.get_type();
	return (*this);
}

void Dog::MakeNoise()
{
	std::cout << "BARK BARK" << std::endl;
}
