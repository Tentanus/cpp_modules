
#include <Weapon>

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{}

const std::string	get_Type() const
{
	return(this->_type);
}

void				set_Type(std::string type)
{
	_type = type;
}

