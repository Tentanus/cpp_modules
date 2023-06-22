#include <phonebook.hpp>

void	PhoneBook::add()
{
	const int32_t	count = this->get_sizef();

	if (count != 8)
	{
		this.add_back();
	}
}
