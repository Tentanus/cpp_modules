#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:

		Zombie(std::string name);
		~Zombie();

		std::string	get_name() const;
		void		announce(void);
		void		randomChump(std::string name);

	private:

		std::string	_name;
} ;

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);

#endif
