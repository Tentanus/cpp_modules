#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <contact.hpp>

typedef enum e_err_num
{
	SUCCESS,
	ERR_INP,
	ERR_COUNT
} t_err_num;

class PhoneBook
{
  private:
	Contact		list[8];
	int32_t		count;

  public:

	PhoneBook();
	~PhoneBook();

	int		get_count();

	void	add();
	void	search();
	void	re_move();
	void	print();

	Contact	get_contact(int32_t i);
};

#endif
