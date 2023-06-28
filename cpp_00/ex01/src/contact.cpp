
#include <iostream>
#include <contact.hpp>

Contact::Contact()
{
	first = "";
	last = "";
	nick = "";
	phone = "";
	secret = "";
}

Contact::~Contact() {}

void	Contact::set_first() {
	std::cout << "First Name:\t";
	std::getline(std::cin, this->first);
}

void	Contact::set_last() {
	std::cout << "Last Name:\t";
	std::getline(std::cin, this->last);
}

void	Contact::set_nick() {
	std::cout << "Nickname:\t";
	std::getline(std::cin, this->nick);
}

void	Contact::set_phone() {
	std::cout << "Phonenumber:\t";
	std::getline(std::cin, this->phone);
}

void	Contact::set_secret() {
	std::cout << "Darkest Secret:\t";

	std::getline(std::cin, this->secret);
}

std::string	Contact::get_first() const
{
	return (this->first);
}

std::string	Contact::get_last() const
{
	return (this->last);
}

std::string	Contact::get_nick() const
{
	return (this->nick);
}

std::string	Contact::get_phone() const
{
	return (this->phone);
}

std::string	Contact::get_secret() const
{
	return (this->secret);
}
