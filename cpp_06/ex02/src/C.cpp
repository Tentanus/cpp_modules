
#include "C.hpp"

C::~C()
{
#ifdef MSG
	std::cout << "Called\tC\tDeconstructor" << std::endl;
#endif
	delete this;
}
