#ifndef INFO_HPP
# define INFO_HPP

typedef enum e_err_num
{
	SUCCESS,
	ERR_INP,
	ERR_FIL,
	ERR_COUNT
} t_err_num;


std::string	get_line(std::string prompt);
int			phonebook_error(int err_code);

#endif
