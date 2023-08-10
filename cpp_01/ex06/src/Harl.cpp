
#include <Harl.hpp>

size_t Harl::complain(std::string lvl)
{
	const size_t max_complaints = sizeof(func_ptr_list) / sizeof(func_ptr);
	size_t complain_lvl = 0;
	size_t i;

	for (i = 0; i < max_complaints; i++)
	{
		complain_lvl = i;
		if (!lvl.compare(lvl_list[i]) && lvl.length() == lvl_list[i].length())
			break;
	}

	if (lvl.compare(lvl_list[max_complaints - 1]) &&
		lvl.length() != lvl_list[max_complaints - 1].length() &&
		i == complain_lvl)
		complain_lvl++;
	return (complain_lvl);
}

void Harl::debug(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "DEBUG INFO" << std::endl;
}

void Harl::error(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "ERROR INFO" << std::endl;
}

void Harl::info(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "INFO INFO" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "WARNING INFO" << std::endl;
}
