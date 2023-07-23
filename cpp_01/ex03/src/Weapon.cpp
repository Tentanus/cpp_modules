
#include <Weapon.hpp>
#include <iostream>

Weapon::Weapon()
{}

Weapon::Weapon(const std::string& type)
{
	_type = type;
	std::cout << "Created Weapon: " << _type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destroyed Weapon: " << _type << std::endl;
}

const std::string&	Weapon::get_Type() const
{
	return(_type);
}

void	Weapon::set_Type(const std::string& type)
{
	_type = type;
}

