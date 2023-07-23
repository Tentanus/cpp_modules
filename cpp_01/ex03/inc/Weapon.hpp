#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	public:
	const std::string	getType();
	void				setType(std::string);

	private:
	std::string	_type;
}

#endif
