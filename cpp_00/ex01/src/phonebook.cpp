
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <phonebook.hpp>

PhoneBook::PhoneBook()
{
	count = 0;
}

PhoneBook::~PhoneBook() {}

Contact	create_contact()
{
	std::string	inp;
	Contact		ret;

	std::cout << "\n" << "Creating Contacts" << std::endl;

	ret.set_first();
	ret.set_last();
	ret.set_nick();
	ret.set_phone();
	ret.set_secret();

	std::cout << std::endl;

	return (ret);
}

void	PhoneBook::add()
{
	if (this->count >= MAX_CONTACT)
		this->count = 0;
	this->list[this->count] = create_contact();
	this->count++;
}

std::string	format_string(std::string str)
{
	if (str.length() < 10)
		return (str + " ");
	else if (str.length() == 10)
		return (str);
	std::string format_str = str.substr(0,9) + ".";
	return (format_str);
}

void	PhoneBook::print_overview()
{
	std::cout << "\n";

	for (int i = 0; i < 4; i++)
		std::cout << "_" << "__________";
	std::cout << "_" << "\n";

	std::cout << "|" << std::setw(10) << std::right << "index ";
	std::cout << "|" << std::setw(10) << std::right << "first ";
	std::cout << "|" << std::setw(10) << std::right << "last ";
	std::cout << "|" << std::setw(10) << std::right << "nickname ";
	std::cout << "|" << "\n";

	for (int i = 0; i < 4; i++)
		std::cout << "|" << "__________";
	std::cout << "|" << "\n";

	for (int i = 0; i < MAX_CONTACT; i++)
	{
		std::cout << "|" << std::setw(9) << i + 1 << " ";
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_first());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_last());
		std::cout << "|" << std::setw(10) << format_string(this->list[i].get_nick());
		std::cout << "|" << "\n";
	}

	for (int i = 0; i < 4; i++)
		std::cout << "|" << "__________";
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_contact(int i)
{
	std::cout << "\n";
	if (this->list[i].get_first().empty())
	{
		std::cout << "Contact is yet to be filled in." << std::endl;
		return ;
	}
	std::cout << "Full Name:\t" << this->list[i].get_first() << " " << this->list[i].get_last() << "\n";
	std::cout << "Nickname:\t" << this->list[i].get_nick() << "\n";
	std::cout << "PhoneNumber:\t" << this->list[i].get_phone() << "\n";
	std::cout << "Darkest Secret:\t" << this->list[i].get_secret() << "\n";
	std::cout << std::endl;
}


void	PhoneBook::search()
{
	std::string	inp;
	int			val_atoi;

	this->print_overview();

	while (1)
	{
		std::cout << "\n" << "Give detailed overview of Contact [1 - " << MAX_CONTACT << "] or EXIT: ";
		std::getline(std::cin, inp);
		val_atoi = std::atoi(inp.c_str());
		if (inp == "EXIT")
			return ;
		else if (val_atoi > 0 && val_atoi <= MAX_CONTACT)
		{
			this->print_contact(val_atoi - 1);
			return ;
		}
		else
			std::cout << "Faulty input: please try again." << std::endl;
	}
}
