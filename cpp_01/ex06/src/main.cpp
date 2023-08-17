
#include <Harl.hpp>

typedef enum e_errcode
{
	ERR_ARG,
	ERR_INP,
	ERR_INF,
	ERR_OUTF,
	ERR_
} t_errcode;

int Harl_error(size_t err)
{
	std::string err_msg[] = {
		"give 2 arguments" // ARG
	};

	std::cerr << "Harlfilter: " << err_msg[err] << std::endl;
	return (err);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (Harl_error(ERR_ARG));

	Harl harl;

	size_t complain_lvl = harl.complain(argv[1]);

	switch (complain_lvl)
	{
	case (0):
		harl.debug();
		harl.info();
		harl.warning();
		harl.error();
		break;
	case (1):
		harl.info();
		harl.warning();
		harl.error();
		break;
	case (2):
		harl.warning();
		harl.error();
		break;
	case (3):
		harl.error();
		break;
	default:
		std::cout << "f:" << __FILE__ << " l:" << __LINE__ << "\t "
				  << "OTHER COMPLAINT INFO" << std::endl;
	}

	return (0);
}
