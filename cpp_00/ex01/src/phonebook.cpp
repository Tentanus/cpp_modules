
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

void	PhoneBook::re_move() {
	int32_t	i;

//	std::cout << "re_move"<< std::endl;
	i = 1;
	do {
		this->list[i - 1] = this->list[i];
		i++;
	}
	while (i != 8);
	this->count--;
}

void	PhoneBook::print()
{
	int32_t	i;
	Contact	tmp;

	i = 0;
	while (i < this->count)
	{
		std::cout << "Contact nbr: " << i + 1 << std::endl;
		tmp = this->list[i];
		std::cout << "\t" << tmp.get_first() << " " << tmp.get_last() << std::endl;
		std::cout << "\t" << tmp.get_nick() << std::endl;
		std::cout << "\t" << tmp.get_phone() << std::endl;
		std::cout << "\t" << tmp.get_secret() << std::endl;
		std::cout << std::endl;
		i++;
	}
}

void	PhoneBook::add() {

//	std::cout << "add_back" << std::endl;
	if (this->count > 8)
		this->count = 1;
	this->list[this->count % 8] = create_contact();
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

void	PhoneBook::search() {
//	std::cout << "search"<< std::endl;

	std::cout << "|" << std::setw(10) << std::right << "index ";
	std::cout << "|" << std::setw(10) << std::right << "first ";
	std::cout << "|" << std::setw(10) << std::right << "last ";
	std::cout << "|" << std::setw(10) << std::right << "nickname ";
	std::cout << "|" << std::endl;
	for (int i = 0; i < 4; i++) 
		std::cout << "|" <<"__________";
	std::cout << "|" << std::endl;

	for (int i = 0; i < this->count; i++) {
		std::cout << "|" << std::setw(9) << i + 1 << " ";
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_first());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_last());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_nick());
		std::cout << "|" << std::endl;
	}
}
