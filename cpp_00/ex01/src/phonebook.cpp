
#include <iostream>
#include <iomanip>
#include <phonebook.hpp>

PhoneBook::PhoneBook() {
	count = 0;
}

PhoneBook::~PhoneBook() {}

int	PhoneBook::get_count() {
	return(this->count);
}

Contact	create_contact() {
	std::string	inp;
	Contact		ret;

	std::cout << std::endl << "Creating Contact" << std::endl;
	ret.set_first();
	ret.set_last();
	ret.set_nick();
	ret.set_phone();
	ret.set_secret();

	return (ret);
}

void	PhoneBook::add() {
//	std::cout << "add_back" << std::endl;
	if (this->count >= 8)
		this->count = 1;
	this->list[this->count] = create_contact();
	this->count++;
}

std::string	format_string(std::string str) {
	if (str.length() < 10)
		return (str + " ");
	else if (str.length() == 10)
		return (str);
	std::string format_str = str.substr(0,9) + ".";
	return (format_str);
}

void	PhoneBook::print_overview() {
	std::cout << "|" << std::setw(10) << std::right << "index ";
	std::cout << "|" << std::setw(10) << std::right << "first ";
	std::cout << "|" << std::setw(10) << std::right << "last ";
	std::cout << "|" << std::setw(10) << std::right << "nickname ";
	std::cout << "|" << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << "|" << "__________";
	std::cout << "|" << std::endl;

	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(9) << i + 1 << " ";
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_first());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_last());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_nick());
		std::cout << "|" << std::endl;
	}

	for (int i = 0; i < 4; i++)
		std::cout << "|" << "__________";
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_contact(int i)
{
	std::cout << "Full Name:\t" << this->list[i].get_first() << " " << this->list[i].get_last() << std::endl;
	std::cout << "Nickname:\t" << this->list[i].get_nick() << std::endl;
	std::cout << "PhoneNumber:\t" << this->list[i].get_phone() << std::endl;
	std::cout << "Darkest Secret:\t" << this->list[i].get_secret() << std::endl;
	std::cout <<  std::endl;
}


void	PhoneBook::search() {
//	std::cout << "search"<< std::endl;
	std::string				inp;

	this->print_overview();

	std::cout << std::endl << "Give detailed overview of Contact [1 - 8] or EXIT: ";
	std::getline(std::cin, inp);
	if (inp == "EXIT")
		return ;
	else if (inp == "1" || \
			inp == "2" || \
			inp == "3" || \
			inp == "4" || \
			inp == "5" || \
			inp == "6" || \
			inp == "7" || \
			inp == "8")
		this->print_contact(std::stoi(inp) - 1);
	else
		std::cout << "Faulty input: returning to menu." << std::endl;

}
