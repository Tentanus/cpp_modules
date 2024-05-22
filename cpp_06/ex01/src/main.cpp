#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data ptr = {42, 4, 2};

	std::cout << ptr << std::endl;
	uintptr_t raw = Serializer::serialize(&ptr);

	std::cout << "ptr:\t" << std::hex << &ptr << std::dec << std::endl;
	std::cout << "raw:\t0x" << std::hex << raw << std::dec << "\n" << std::endl;

	Data *test = Serializer::deserialize(raw);
	std::cout << *test << std::endl;

	return (0);
}
