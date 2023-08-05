#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	public:
	void complain (std::string lvl);

	private:
	void debug (void);
	void error (void);
	void info (void);
	void warning (void);

	const std::string lvl_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
};

#endif
