
#include "Iter.hpp"

int main(void)
{
	int iarr[6] = {0, 1, 2, 3, 4};

	std::cout << "Values in iarr\n";
	for (size_t i = 0; i < 5; i++)
		std::cout << "i: " << i << "\tval: " << iarr[i] << "\n";
	std::cout << std ::endl;

	::iter(iarr, 5, ::mult);

	std::cout << "\nValues in iarr\n";
	for (size_t i = 0; i < 5; i++)
		std::cout << "i: " << i << "\tval: " << iarr[i] << "\n";
	std::cout << std ::endl;

	float farr[6] = {0.2, 1.5, 2.2, 3.3, 4.7};

	std::cout << "Values in farr\n";
	for (size_t i = 0; i < 5; i++)
		std::cout << "i: " << i << "\tval: " << farr[i] << "\n";
	std::cout << std ::endl;

	::iter(farr, 5, ::mult);

	std::cout << "\nValues in farr\n";
	for (size_t i = 0; i < 5; i++)
		std::cout << "i: " << i << "\tval: " << farr[i] << "\n";
	std::cout << std ::endl;
}
