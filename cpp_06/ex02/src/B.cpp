
#include "B.hpp"

B::~B()
{
#ifdef MSG
	std::cout << "Called\tB\tDeconstructor" << std::endl;
#endif
	delete this;
}
