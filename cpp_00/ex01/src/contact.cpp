
#include <iostream>
#include <contact.hpp>

void	Contact::set_first()
{
	std::string	inp;

	while (1)
	{
		std::cout << "First Name:\t";
		std::getline(std::cin, inp);
		size_t	pos = inp.find_first_of(" \t\r\v\n");
		if (!inp.empty() && pos == SIZE_MAX)
			break ;
		if (!pos || pos == SIZE_MAX)
			inp.erase();
		else
			inp[pos] = '\0';
		if (!inp.empty())
			break ;
		std::cout << "No input recieved, try again" << std::endl;
	}
	this->first = inp;
}

void	Contact::set_last()
{
	std::string	inp;

	while (1)
	{
		std::cout << "Last Name:\t";
		std::getline(std::cin, inp);
		size_t	pos = inp.find_first_of(" \t\r\v\n");
		if (!inp.empty() && pos == SIZE_MAX)
			break ;
		if (!pos || pos == SIZE_MAX)
			inp.erase();
		else
			inp[pos] = '\0';
		if (!inp.empty())
			break ;
		std::cout << "No input recieved, try again" << std::endl;
	}
	this->last = inp;
}

void	Contact::set_nick()
{
	std::string	inp;

	while (1)
	{
		std::cout << "Nickname:\t";
		std::getline(std::cin, inp);
		size_t	pos = inp.find_first_of(" \t\r\v\n");
		if (!inp.empty() && pos == SIZE_MAX)
			break ;
		if (!pos || pos == SIZE_MAX)
			inp.erase();
		else
			inp[pos] = '\0';
		if (!inp.empty())
			break ;
		std::cout << "No input recieved, try again" << std::endl;
	}
	this->nick = inp;
}

void	Contact::set_phone()
{
	std::string	inp;

	while (1)
	{
		std::cout << "Phonenumber:\t";
		std::getline(std::cin, inp);
		size_t	pos = inp.find_first_of(" \t\r\v\n");
		if (!inp.empty() && pos == SIZE_MAX)
			break ;
		if (!pos || pos == SIZE_MAX)
			inp.erase();
		else
			inp[pos] = '\0';
		if (!inp.empty())
			break ;
		std::cout << "No input recieved, try again" << std::endl;
	}
	this->phone = inp;
}

void	Contact::set_secret()
{
	std::string	inp;

	while (1)
	{
		std::cout << "Darkest Secret:\t";
		std::getline(std::cin, inp);
		size_t	pos = inp.find_first_of(" \t\r\v\n");
		if (!inp.empty() && pos == SIZE_MAX)
			break ;
		if (!pos || pos == SIZE_MAX)
			inp.erase();
		else
			inp[pos] = '\0';
		if (!inp.empty())
			break ;
		std::cout << "No input recieved, try again" << std::endl;
	}
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
