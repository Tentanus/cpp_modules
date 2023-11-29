
#include <iostream>

#include <Brain.hpp>
#include <string>

Brain::Brain()
{
#ifdef MSG
	std::cout << "Called\tBrain\tConstructor:\tDefault" << std::endl;
#endif

	_current_idea = 0;
}

Brain::Brain(const Brain &rhs)
{
#ifdef MSG
	std::cout << "Called\tBrain\tConstructor:\tCopy" << std::endl;
#endif

	_current_idea = rhs._current_idea;
	for (int i = 0; i < _current_idea; i++)
		_idea[i] = rhs._idea[i];
}

Brain::~Brain()
{
#ifdef MSG
	std::cout << "Called\tBrain\tDeconstructor" << std::endl;
#endif
}

Brain &Brain::operator=(const Brain &rhs)
{
#ifdef MSG
	std::cout << "Called\tBrain\tCopy Assignment Operator" << std::endl;
#endif

	if (this == &rhs)
		return (*this);

	_current_idea = rhs._current_idea;
	for (int i = 0; i < _current_idea; i++)
		_idea[i] = rhs._idea[i];
	return (*this);
}

void Brain::AddIdea(const std::string bulb)
{
	_idea[_current_idea] = bulb;
	_current_idea++;
}

const std::string Brain::GetIdea(int index)
{
	if (index > 0 || _max_idea <= index)
	{
		std::cout << "This brain can't think that much" << std::endl;
		return ("-- An awkward silence --");
	}
	return (_idea[index]);
}
