
#include <iostream>
#include <phonebook.hpp>

std::string g_err_msg[] = {
	"SUCCESS",
	"incorrect input [ADD/SEARCH/EXIT]",
	"ERR_COUNT"
};

int phonebook_error(int err_code)
{
	std::cerr << "phonebook: " << g_err_msg[err_code] << std::endl;
	return (err_code);
}

int main()
{
	std::string	input;
	PhoneBook	pb;

	pb.count = 0;
	while (1)
	{
		std::cout << "Enter command [ADD/SEARCH/EXIT]: ";
		std::getline(std::cin, input);
		if (input == "SEARCH")
			pb.search();
		else if (input == "ADD")
			pb.add_back();
		else if (input == "EXIT")
			return (0);
		else
			phonebook_error(ERR_INP);
	}
}
