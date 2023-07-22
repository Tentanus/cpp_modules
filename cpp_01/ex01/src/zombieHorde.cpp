
#include <Zombie.hpp>
#include <iostream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombie_ret = new Zombie[N];
	Zombie zombie_tmp = Zombie(name);

	for (unsigned int i = 0; i < (unsigned int) N; i++)
	{
		zombie_ret[i] = zombie_tmp;
		zombie_ret[i].announce();
	}

	return (zombie_ret);
}

// for some reason i don't know yet the returned pointer segfaults or is freed multiple times.
