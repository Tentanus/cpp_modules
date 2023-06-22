#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

	public:
	
};



typedef enum e_err_num
{
	SUCCESS = 1,
	ERR_INP,
	ERR_COUNT
} t_err_num;

class PhoneBook
{
  private:
	Contact list[8];
	int		count;

  public:
};

#endif
