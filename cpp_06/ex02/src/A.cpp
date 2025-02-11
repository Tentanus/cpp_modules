
#include "A.hpp"

//-------------------Orthodox Canonical Form-------------------//

A::A()
{
	#ifdef MSG
		std::cout << "Called\tA\tConstructor:\tDefault" << std::endl;
	#endif
}
A::A(const A &rhs)
{
	#ifdef MSG
		std::cout << "Called\tA\tConstructor:\tCopy" << std::endl;
	#endif
	(void)rhs;

}

A &A::operator=(const A &rhs)
{
	#ifdef MSG
		std::cout << "Called\tA\tcopy Assignment Operator" << std::endl;
	#endif
	(void)rhs;
	return (*this);
}

A::~A()
{
	#ifdef MSG
		std::cout << "Called\tA\tDeconstructor" << std::endl;
	#endif
}
