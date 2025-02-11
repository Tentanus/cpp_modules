#include "Data.hpp"

std::ostream &operator<<(std::ostream &os, const Data &ptr)
{
	std::cout << 	"Data:\n" <<
					"_:\t" << ptr.data << "\n"
					"x:\t" << ptr.x << "\n"
					"y:\t" << ptr.y << "\n" << std::endl;
	return (os);
}