#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <contact.hpp>

# define MAX_CONTACT 8

typedef enum e_err_num
{
	SUCCESS,
	ERR_INP,
	ERR_COUNT
} t_err_num;

class PhoneBook
{
  private:
	Contact		list[MAX_CONTACT];
	int			count;

  public:

	PhoneBook();
	~PhoneBook();

	void	add();
	void	search();
	void	print_overview();
	void	print_contact(int i);
};

#endif
