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
	void	add_back();
	void	search();
	void	re_move();
};

#endif
