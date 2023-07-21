
#include <string>
#include <iostream>
#include <Zombie.hpp>

void	Zombie::announce(void)
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::get_name(void) const
{
	return (this->_name);
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie " << this->get_name() << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->get_name() << " destroyed" << std::endl;
}

