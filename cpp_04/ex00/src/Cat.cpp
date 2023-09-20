
#include <iostream>
#include <string>

#include <Cat.hpp>

Cat::Cat() : Animal()
{
#ifdef MSG
	std::cout << "Called\tCat\tConstructor:\tDefault" << std::endl;
#endif
	set_type("Cat");
}

Cat::Cat(Cat &inp) : Animal()
{
#ifdef MSG
	std::cout << "Called\tCat\tConstructor\tCopy" << std::endl;
#endif
	set_type(inp.get_type());
}

Cat::~Cat()
{
#ifdef MSG
	std::cout << "Called\tCat\tDeconstructor" << std::endl;
#endif
}

Cat Cat::operator=(const Cat &inp)
{
#ifdef MSG
	std::cout << "Called\tCat\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &inp)
		_type = inp.get_type();
	return (*this);
}

void Cat::MakeNoise()
{
	std::cout << "Miaow Miaow" << std::endl;
}
