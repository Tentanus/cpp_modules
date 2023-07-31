
#include <iostream>

int	rep_error(size_t err)
{
	std::string err_msg[] = {
	[]
	};

	std::cout << "repline: ";
	std::cout << err_msg[err] << std::endl;
	return (err);
}

int main(int argv, char **argv)
{
	if (argv != 4)
		return (rep_error());
}
