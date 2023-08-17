
#include <Harl.hpp>

size_t Harl::complain(std::string lvl)
{
	const size_t max_complaints = sizeof(func_ptr_list) / sizeof(func_ptr);
	int complain_lvl = -1;

	for (size_t i = 0; i < max_complaints; i++)
	{
		if (!lvl.compare(lvl_list[i]) && lvl.length() == lvl_list[i].length())
		{
			complain_lvl = i;
			break;
		}
	}

	if (complain_lvl == -1)
		return (sizeof(func_ptr_list));
	return (complain_lvl);
}

void Harl::debug(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "DEBUG INFO" << std::endl;
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

void Harl::error(void)
{
	std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
			  << "ERROR INFO" << std::endl;
}
