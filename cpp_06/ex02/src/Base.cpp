
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *Base::generate(void)
{
	int nbr = rand();
	std::cout << "generate: random number: " << nbr << std::endl;
	switch (nbr % 3)
	{
	case 0:
		std::cout << "generate: returned new A" << std::endl;
		return (new A());
	case 1:
		std::cout << "generate: returned new B" << std::endl;
		return (new B());
	case 2:
		std::cout << "generate: returned new C" << std::endl;
		return (new C());
	default:
		std::cout << "generate: returned nullptr" << std::endl;
		return (NULL);
	}
}

void Base::identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "identify *: identied A class" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "identify *: identied B class" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "identify *: identied C class" << std::endl;
	else
		std::cout << "identify *: unfamiliar class"
				  << std::endl; // this could throw an exception
}

void Base::identify(Base &ref)
{
	if (dynamic_cast<A *>(&ref))
		std::cout << "identify &: identied A class" << std::endl;
	else if (dynamic_cast<B *>(&ref))
		std::cout << "identify &: identied B class" << std::endl;
	else if (dynamic_cast<C *>(&ref))
		std::cout << "identify &: identied C class" << std::endl;
	else
		std::cout << "identify &: unfamiliar class"
				  << std::endl; // this could throw an exception
}

Base::~Base()
{
#ifdef MSG
	std::cout << "Called\tBase\tDeconstructor" << std::endl;
#endif
}
