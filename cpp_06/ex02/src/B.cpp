
#include "B.hpp"

//-------------------Orthodox Canonical Form-------------------//

B::B()
{
	#ifdef MSG
		std::cout << "Called\tB\tConstructor:\tDefault" << std::endl;
	#endif
}
B::B(const B &rhs)
{
	#ifdef MSG
		std::cout << "Called\tB\tConstructor:\tCopy" << std::endl;
	#endif
	(void)rhs;

}

B &B::operator=(const B &rhs)
{
	#ifdef MSG
		std::cout << "Called\tB\tcopy Assignment Operator" << std::endl;
	#endif
	(void)rhs;
	return (*this);
}

B::~B()
{
	#ifdef MSG
		std::cout << "Called\tB\tDeconstructor" << std::endl;
	#endif
}
