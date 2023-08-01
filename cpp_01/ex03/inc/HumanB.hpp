#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <Weapon.hpp>

class HumanB
{
	public:
		HumanB(const std::string name);
		~HumanB();

		const Weapon&		get_Weapon() const;
		const std::string	get_name() const;
		void				set_Weapon(Weapon& weapon);

		void				attack();

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
