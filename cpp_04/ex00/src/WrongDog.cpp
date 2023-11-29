
#include <iostream>
#include <string>

#include <WrongDog.hpp>

WrongDog::WrongDog() : WrongAnimal()
{
#ifdef MSG
	std::cout << "Called\tWrongDog\tConstructor:\tDefault" << std::endl;
#endif
	set_type("WrongDog");
}

WrongDog::WrongDog(WrongDog &rhs) : WrongAnimal()
{
#ifdef MSG
	std::cout << "Called\tWrongDog\tConstructor\tCopy" << std::endl;
#endif
	set_type(rhs.get_type());
}

WrongDog::~WrongDog()
{
#ifdef MSG
	std::cout << "Called\tWrongDog\tDeconstructor" << std::endl;
#endif
}

WrongDog WrongDog::operator=(const WrongDog &rhs)
{
#ifdef MSG
	std::cout << "Called\tWrongDog\tCopy Assignment Operator" << std::endl;
#endif
	if (this != &rhs)
		_type = rhs.get_type();
	return (*this);
}

void WrongDog::MakeNoise()
{
	std::cout << "BARK BARK" << std::endl;
}
