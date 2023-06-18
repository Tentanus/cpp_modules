#include <string>
#include <iostream>

#include <phonebook.hpp>

static const std::string g_err_msg[ERR_COUNT] = {
		"SUCCES",
		"incorrect input: use ADD, SEARCH, EXIT",
		"ERR_COUNT"
};

int	phonebook_error(int err_code) {
	std::cerr << "phonebook: " << g_err_msg[err_code] << std::endl;
	return (err_code);
}

void	phonebook_add(void) {
	std::cout << "inside phonebook_add" << std::endl;
}


void	phonebook_search(void) {
	std::cout << "inside phonebook_search" << std::endl;
}

int main() {
	std::string	input;
	PhoneBook	phonebook;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		input.erase(0, input.find_first_not_of(" \t\v\r\f"));
		input.erase(input.find_last_not_of(" \t\v\r\f"), input.end());
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook_add();
		else if (input == "SEARCH")
			phonebook_search();
		else
			return (phonebook_error(ERR_INP));
	}
}
