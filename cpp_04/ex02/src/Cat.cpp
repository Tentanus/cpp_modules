
#include <iostream>
#include <string>

#include <Cat.hpp>

Cat::Cat() : AAnimal()
{
#ifdef MSG
	std::cout << "Called\tCat\tConstructor:\tDefault" << std::endl;
#endif

	set_type("Cat");
	_brain = new Brain;
}

Cat::Cat(Cat &rhs) : AAnimal()
{
#ifdef MSG
	std::cout << "Called\tCat\tConstructor\tCopy" << std::endl;
#endif

	set_type(rhs.get_type());
	_brain = new Brain(*rhs._brain);
}

Cat::~Cat()
{
#ifdef MSG
	std::cout << "Called\tCat\tDeconstructor" << std::endl;
#endif

	delete _brain;
}

Cat Cat::operator=(const Cat &rhs)
{
#ifdef MSG
	std::cout << "Called\tCat\tCopy Assignment Operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void Cat::MakeNoise()
{
	std::cout << "Miaow Miaow" << std::endl;
}

void Cat::AddIdea(const std::string idea)
{
	_brain->AddIdea(idea);
}

const std::string Cat::readBrain(int index)
{
	return (_brain->GetIdea(index));
}
