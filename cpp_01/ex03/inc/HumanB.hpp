#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanB
{
	public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon weapon);
	~HumanB();

	void				attack();

	private:
	std::string	_name;
	Weapon		_weapon;
}

#endif
