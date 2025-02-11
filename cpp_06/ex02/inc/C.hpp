#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
  public:
  C();
	C(const C &rhs);
	C &operator=(const C &rhs);
	~C();
};

#endif // !C_HPP
