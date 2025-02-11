
#include "Base.hpp"

int main(void)
{

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "\n";
		srand(time(0));
		Base *ptr = Base::generate();
		Base::identify(ptr);
		Base::identify(*ptr);
		delete ptr;
		std::cout << "\n";
		sleep(1);
	}

	std::cout << "Checking NULL ptr\n";
	Base *ptr = NULL;
	Base::identify(ptr);
	Base::identify(*ptr);
	std::cout << std::endl;

	return (0);
}
