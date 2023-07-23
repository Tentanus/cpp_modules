#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	public:
	Weapon(std::string type);
	~Weapon();

	const std::string	get_Type() const;
	void				set_Type(std::string type);

	private:
	std::string	_type;
}

#endif
