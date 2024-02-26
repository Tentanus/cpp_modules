#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data ptr = {42, 6, 9};

	std::cout << ptr << std::endl;
	uintptr_t raw = Serializer::serialize(&ptr);

	std::cout << "raw:  " << raw << "\t" << std::hex << raw << std::dec << "\n"
			  << std::endl;

	Data *test = Serializer::deserialize(raw);
	std::cout << *test << std::endl;

	return (0);
}
