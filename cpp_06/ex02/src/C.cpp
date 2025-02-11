
#include "C.hpp"

//-------------------Orthodox Canonical Form-------------------//

C::C()
{
	#ifdef MSG
		std::cout << "Called\tC\tConstructor:\tDefault" << std::endl;
	#endif
}
C::C(const C &rhs)
{
	#ifdef MSG
		std::cout << "Called\tC\tConstructor:\tCopy" << std::endl;
	#endif
	(void)rhs;

}

C &C::operator=(const C &rhs)
{
	#ifdef MSG
		std::cout << "Called\tC\tcopy Assignment Operator" << std::endl;
	#endif
	(void)rhs;
	return (*this);
}

C::~C()
{
	#ifdef MSG
		std::cout << "Called\tC\tDeconstructor" << std::endl;
	#endif
}
