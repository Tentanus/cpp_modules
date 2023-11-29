
#include <iostream>
#include <string>

#include <Dog.hpp>

Dog::Dog() : Animal()
{
#ifdef MSG
	std::cout << "Called\tDog\tConstructor:\tDefault" << std::endl;
#endif

	set_type("Dog");
	_brain = new Brain;
}

Dog::Dog(Dog &rhs) : Animal()
{
#ifdef MSG
	std::cout << "Called\tDog\tConstructor\tCopy" << std::endl;
#endif

	set_type(rhs.get_type());
	_brain = new Brain(*rhs._brain);
}

Dog::~Dog()
{
#ifdef MSG
	std::cout << "Called\tDog\tDeconstructor" << std::endl;
#endif

	delete _brain;
}

Dog Dog::operator=(const Dog &rhs)
{
#ifdef MSG
	std::cout << "Called\tDog\tCopy Assignment Operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void Dog::MakeNoise()
{
	std::cout << "BARK BARK" << std::endl;
}

void Dog::AddIdea(const std::string idea)
{
	_brain->AddIdea(idea);
}
