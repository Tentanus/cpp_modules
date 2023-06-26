
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

Contact	PhoneBook::get_contact(int32_t i)
{
	return (this->list[i]);
}
void	PhoneBook::print()
{
	int32_t	i;
	Contact	tmp;
	std::string	str;

	i = 0;
	while (i < 8)
	{
		tmp = this->get_contact(i);
		str = tmp.get_first;
		std::cout << str << " " << tmp.get_last << std::endl;
		std::cout << tmp.get_nick << std::endl;
		std::cout << tmp.get_phone << std::endl;
		std::cout << tmp.get_secret << std::endl;
		i++;
	}
}

void	PhoneBook::add_back()
{
	const int32_t	count = this->count;

//	std::cout << "add_back" << std::endl;
	if (count == 8)
		this->re_move();
	this->list[count] = create_contact();
	this->count++;
	this->print();
}

void	PhoneBook::search()
{
	std::cout << "search"<< std::endl;
}
