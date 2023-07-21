#include <iostream>
#include <contact.hpp>

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::set_first()
{
	std::string	input;
	while (1)
	{
		input = get_line("Fist Name:\t");
		if (!input.empty())
			break;
		phonebook_error(ERR_FIL);
	}
	this->first = input;
}

void	Contact::set_last()
{
	std::string	input;
	while (1)
	{
		input = get_line("Last Name:\t");
		if (!input.empty())
			break;
		phonebook_error(ERR_FIL);
	}
	this->last= input;
}

void	Contact::set_nick()
{
	std::string	input;
	while (1)
	{
		input = get_line("Nickname:\t");
		if (!input.empty())
			break;
		phonebook_error(ERR_FIL);
	}
	this->nick= input;
}

void	Contact::set_phone()
{
	std::string	input;
	while (1)
	{
		input = get_line("Phonenumber:\t");
		if (!input.empty())
			break;
		phonebook_error(ERR_FIL);
	}
	this->phone = input;
}

void	Contact::set_secret()
{
	std::string	input;
	while (1)
	{
		input = get_line("Darkest Secret:\t");
		if (!input.empty())
			break;
		phonebook_error(ERR_FIL);
	}
	this->secret = input;
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

