
#include "Iter.hpp"

template <typename T>
void showArray(const T * const ptr, const size_t n, const std::string type)
{

	std::cout << "Values in iarr (type: " << type << ")\n";
	for (size_t i = 0; i < n; i++)
		std::cout << "ptr[" << i << "]:\t" << ptr[i] << "\n";
	std::cout << std ::endl;

}

int main(void)
{
	int iarr[6] = {0, 1, 2, 3, 4};

	showArray(iarr, 5, "int");
	::iter(iarr, 5, ::mult);
	showArray(iarr, 5, "int");
	
	float farr[6] = {0.2, 1.5, 2.2, 3.3, 4.7};

	showArray(farr, 5, "float");
	::iter(farr, 5, ::mult);
	showArray(farr, 5, "float");

	std::string sarr[6] = {"hey", "wow", "", "Heya", "032"};

	showArray(sarr, 5, "string");
	::iter(sarr, 5, ::capital);
	showArray(sarr, 5, "string");

}
