#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main()
{
	try
	{
		std::vector<int> vec;
		for (int i = 1; i < 5; i++)
			vec.push_back(i);

		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found value: " << *it << std::endl;

		std::list<int> lst;
		for (int i = 1; i < 5; i++)
			lst.push_back(i);

		std::list<int>::iterator it2 = easyfind(lst, 3);
		std::cout << "Found value: " << *it2 << std::endl;

		std::list<int>::iterator it3 = easyfind(lst, 60);
		std::cout << "Found value: " << *it3 << std::endl;
	}
	catch (const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
