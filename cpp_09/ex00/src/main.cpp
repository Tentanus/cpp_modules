#include "BitcoinExchange.hpp"

void validateFile(int argc, char **argv, std::stringstream &ss)
{
	if (argc != 3)
		throw std::runtime_error("expected one input file " +
								 std::string(argv[0]) +
								 " [datafile.csv] [inputfile.txt]");
	const std::string datafile(argv[1]);
	if (datafile.find(".csv") != datafile.length() - 4)
		throw std::runtime_error("expected a datafile with extention \'.csv\'");
	const std::string inputfile(argv[2]);
	if (inputfile.find(".txt") != inputfile.length() - 4)
		throw std::runtime_error(
			"expected an inputfile with extention \'.txt\'");
	std::ifstream data_fs;
	data_fs.open(argv[1], std::ios_base::in);
	if (!data_fs.is_open())
		throw std::runtime_error("unable to open file");
	ss << data_fs.rdbuf();
}

int main(int argc, char **argv)
{
	std::stringstream ss;
	try
	{
		validateFile(argc, argv, ss);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	BitcoinExchange btc(ss);
	std::ifstream infile_fs(argv[2], std::ios_base::in);
	std::stringstream infile_ss;
	infile_ss << infile_fs.rdbuf();
	btc.takeInfile(infile_ss, std::string(argv[2]));
}