#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		size_t	complain (std::string lvl);
		void	debug (void);
		void	error (void);
		void	info (void);
		void	warning (void);

	private:

	const std::string lvl_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	typedef void (Harl::*func_ptr)();
	const func_ptr func_ptr_list[4] = {
		&Harl::debug,
		&Harl::error,
		&Harl::info,
		&Harl::warning
	} ;
};

#endif
