#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <info.hpp>
# include <contact.hpp>

# define MAX_CONTACT 8

class PhoneBook
{
  private:

	Contact	list[MAX_CONTACT];
	int		count;

	void	print_overview();
	void	print_contact(int i);

  public:

	PhoneBook();
	~PhoneBook();

	void	add();
	void	search();
};

#endif
