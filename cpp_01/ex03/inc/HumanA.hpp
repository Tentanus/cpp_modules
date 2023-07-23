#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
	public:
	HumanA(std::string name, Weapon weapon);
	~HumanA();

	void		set_Weapon(Weapon weapon);
	Weapon		get_Weapon();

	void				attack();

	private:
	std::string	_name;
	Weapon		_weapon;
}

#endif
