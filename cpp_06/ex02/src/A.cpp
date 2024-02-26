
#include "A.hpp"

A::~A()
{
#ifdef MSG
	std::cout << "Called\tA\tDeconstructor" << std::endl;
#endif
	delete this;
}
