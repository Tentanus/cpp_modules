
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <tester.hpp>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	std::vector<int> numbers{1, 2, 3, 2, 4, 5, 2, 6, 7};

	// Get iterators to the first and second occurrence of the value 2
	std::vector<int>::iterator it1 =
		std::find(numbers.begin(), numbers.end(), 2);
	std::vector<int>::iterator it2 = std::find(it1 + 3, numbers.end(), 2);

	// Compare the iterators
	while (it1 != numbers.end())
	{
		if (it1 == it2)
		{
			std::cout
				<< "Iterators point to the same position in the vector. \tit1: "
				<< *it1 << " it2: " << *it2 << std::endl;
		}
		else
		{
			std::cout << "Iterators point to different positions in the "
						 "vector.\tit1: "
					  << *it1 << " it2: " << *it2 << std::endl;
		}
		it1++;
	}
	return 0;
}

// You can compare Vector::iterators originating from the same vector
