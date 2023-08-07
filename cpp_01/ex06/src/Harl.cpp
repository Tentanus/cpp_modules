
#include <Harl.hpp>

size_t	Harl::complain (std::string lvl)
{
	const size_t max_complaints = sizeof(func_ptr_list) / sizeof(func_ptr);
	size_t		 complain_lvl;

	for (size_t i = 0; i < max_complaints; i++) {
		if (lvl == lvl_list[i]) {
			complain_lvl = i;
			break;
		}
	}

	return (complain_lvl);
}

void	Harl::debug (void) {
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "DEBUG INFO" << std::endl;
}

void	Harl::error (void) {
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "ERROR INFO" << std::endl;
}

void	Harl::info (void) {
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "INFO INFO" << std::endl;
}

void	Harl::warning (void) {
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "WARNING INFO" << std::endl;
}
