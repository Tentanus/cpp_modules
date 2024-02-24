#include "Serializer.hpp"

std::ostream &operator<<(std::ostream &os, const Data &ptr)
{
	std::cout << 	"Data:\n" <<
					"_:\t" << ptr.data << "\n"
					"x:\t" << ptr.x << "\n"
					"y:\t" << ptr.y << "\n" << std::endl;
	return (os);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
