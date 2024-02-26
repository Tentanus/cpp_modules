#include "Serializer.hpp"

// clang-format off
std::ostream &operator<<(std::ostream &os, const Data &ptr)
{
	std::cout << 	"Data:\n" <<
					"_:\t" << ptr.data << "\n"
					"x:\t" << ptr.x << "\n"
					"y:\t" << ptr.y << "\n" << std::endl;
	return (os);
}
// clang-format on

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

//-------------------Orthodox Canonical Form-------------------//

Serializer::Serializer()
{
#ifdef MSG
	std::cout << "Called\tSerializer\t\tConstructor:\tDefualt" << std::endl;
#endif
}

Serializer::Serializer(const Serializer &rhs)
{
#ifdef MSG
	std::cout << "Called\tSerializer\tConstructor:\tCopy" << std::endl;
#endif
	(void)rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
#ifdef MSG
	std::cout << "Called\tSerializer\tCopy Assignment Operator" << std::endl;
#endif
	(void)rhs;
	return (*this);
}

Serializer::~Serializer()
{
#ifdef MSG
	std::cout << "Called\tSerializer\t\tDeconstructor" << std::endl;
#endif
}
