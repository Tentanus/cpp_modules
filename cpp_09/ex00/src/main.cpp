#include "BitcoinExchange.hpp"

void validateFile(int argc, char **argv)
{
	if (argc != 3)
		throw std::runtime_error("expected one input file " + std::string(argv[0]) + " [datafile.csv] [inputfile.txt]");
	const std::string datafile(argv[1]);
	if (datafile.find(".csv") != datafile.length() - 4)
		throw std::runtime_error("expected a datafile with extention \'.csv\'");
	const std::string inputfile(argv[2]);
	if (inputfile.find(".txt") != inputfile.length() - 4)
		throw std::runtime_error("expected an inputfile with extention \'.txt\'");
}

int main (int argc, char **argv)
{
	std::ifstream data_fs;
	try {
		validateFile(argc, argv);
		data_fs.open(argv[1], std::ios_base::in);
		if (!data_fs.is_open())
			throw std::runtime_error("unable to open file");
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	// BicoinExchange btc(data_fs, )
}