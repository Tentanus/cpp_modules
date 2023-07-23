#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <Weapon.hpp>

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB();

		const Weapon&		get_Weapon() const;
		void				set_Weapon(const Weapon& weapon);
		const std::string&	get_name() const;

		void				attack();

	private:
		std::string	_name;
		Weapon		_weapon;
};

#endif
