
#include <iostream>
#include <phonebook.hpp>

std::string g_err_msg[] = {
	"SUCCESS",
	"incorrect input [ADD/SEARCH/EXIT]",
	"incorrect input [NO whitespaces, NO empty string]",
	"ERR_COUNT"
};

int phonebook_error(int err_code)
{
	std::cerr << "\nphonebook: " << g_err_msg[err_code] << std::endl;
	return (err_code);
}

std::string	get_line(std::string prompt)
{
	std::string	ret;

	std::cout << prompt;
	std::getline(std::cin, ret);
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
	}
	if (ret.empty() || \
		ret.find(" ") != SIZE_MAX || \
		ret.find('\t') != SIZE_MAX || \
		ret.find('\n') != SIZE_MAX || \
		ret.find('\v') != SIZE_MAX || \
		ret.find('\r') != SIZE_MAX)
		return ("");
	return (ret);
}

int main()
{
	std::string	input;
	PhoneBook	pb;

	while (1)
	{
		input = get_line("Enter command [ADD/SEARCH/EXIT]: ");
		if (input == "EXIT")
			return (0);
		else if (input == "SEARCH")
			pb.search();
		else if (input == "ADD")
			pb.add();
		else
			phonebook_error(ERR_INP);
	}
}
