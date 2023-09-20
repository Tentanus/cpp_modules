
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

Dog::Dog(Dog &inp) : Animal()
{
#ifdef MSG
	std::cout << "Called\tDog\tConstructor\tCopy" << std::endl;
#endif
	set_type(inp.get_type());
}

Dog::~Dog()
{
#ifdef MSG
	std::cout << "Called\tDog Deconstructor" << std::endl;
#endif
}

Dog Dog::operator=(const Dog &inp)
{
#ifdef MSG
	std::cout << "Called\tDog\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &inp)
		_type = inp.get_type();
	return (*this);
}
