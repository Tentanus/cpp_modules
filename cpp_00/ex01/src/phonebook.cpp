
#include <iostream>
#include <phonebook.hpp>

Contact	create_contact()
{
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

void	PhoneBook::re_move()
{
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

void	PhoneBook::add_back()
{
	const int32_t	count = this->count;

//	std::cout << "add_back" << std::endl;
	if (count == 8)
		this->re_move();
	this->list[count] = create_contact();
	this->count++;
}

void	PhoneBook::search()
{
	std::cout << "search"<< std::endl;
}
