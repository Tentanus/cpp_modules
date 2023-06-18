#include <string>
#include <iostream>

#include <phonebook.hpp>

int main() {
	std::string			input;
	std::istringstream	iss;
	PhoneBook			phonebook;

	while (1) {
		std::cin >> input;
		iss(input);
		iss >> word
		
		switch (word) {
			case 'EXIT':
				return (0);
			case 'ADD':
				;
			case 'SEARCH':
				;
			default:
				cerr << "FAULTY INPUT, TRY AGAIN" << std::endl;
		}
	}
}
