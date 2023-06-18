#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <contact.hpp>

typedef enum e_err_num {
	SUCCESS = 1,
	ERR_INP,
	ERR_COUNT
}	t_err_num;

class PhoneBook {
private:
	Contact		list[9];
} ;

#endif
