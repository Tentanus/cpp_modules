
#include "Array.hpp"

int main(void)
{
	long *a = new long[3];

	for (int i = 0; i < 5; i++)
	{
		std::cout << "[" << a[i] << "] ";
		a[i] = LONG_MAX - i;
		std::cout << "[" << a[i] << "] " << std::endl;
	}

	delete[] a;
	return (0);
}
