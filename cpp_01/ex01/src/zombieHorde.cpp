
#include <Zombie.hpp>
#include <iostream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie_ret = new Zombie[N];
	Zombie	zombie_tmp = Zombie(name);

	for (unsigned int i = 0; i < (unsigned int) N; i++)
		zombie_ret[i] = zombie_tmp;

	return (zombie_ret);
}
