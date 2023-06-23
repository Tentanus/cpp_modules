
#include <iostream>
#include <contact.hpp>

void	Contact::set_first()
{
	std::string	inp;
	std::cout << "First Name:\t";
	std::cin >> inp;
	this->first = inp;
}

void	Contact::set_last()
{
	std::string	inp;
	std::cout << "Last Name:\t";
	std::cin >> inp;
	this->last = inp;
}

void	Contact::set_nick()
{
	std::string	inp;
	std::cout << "Nickname:\t";
	std::cin >> inp;
	this->nick = inp;
}

void	Contact::set_phone()
{
	std::string	inp;
	std::cout << "Phonenumber:\t";
	std::cin >> inp;
	this->phone = inp;
}

void	Contact::set_secret()
{
	std::string	inp;
	std::cout << "Darkest Secret:\t";
	std::cin >> inp;
	this->secret = inp;
}

std::string	Contact::get_first()
{
	return (this->first);
}

std::string	Contact::get_last()
{
	return (this->last);
}

std::string	Contact::get_nick()
{
	return (this->nick);
}

std::string	Contact::get_phone()
{
	return (this->phone);
}

std::string	Contact::get_secret()
{
	return (this->secret);
}
