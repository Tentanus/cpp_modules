
#include "Base.hpp"

int main(void)
{

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "\n";
		sleep(1);
		srand(time(0));
		Base *ptr = Base::generate();
		std::cout << "\n";
		Base::identify(ptr);
		Base::identify(*ptr);
		std::cout << "\n";
	}

	std::cout << "Checking NULL ptr\n";
	Base *ptr = NULL;
	Base::identify(ptr);
	Base::identify(*ptr);
	std::cout << std::endl;

	return (0);
}
