#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:
		void	complain(std::string lvl);
	private:
		void	debug(void);
		void	error(void);
		void	info(void);
		void	warning(void);

		const std::string	lvl_list[4] = {
			"DEBUG",
			"ERROR",
			"INFO",
			"WARNING"
		} ;

		typedef void (Harl::*func_ptr)();
		const func_ptr func_ptr_list[4] = {
			&Harl::debug,
			&Harl::error,
			&Harl::info,
			&Harl::warning
		} ;
} ;

#endif
