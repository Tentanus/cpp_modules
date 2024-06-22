#include "BitcoinExchange.hpp"
#include <regex>
#include <string>

void BitcoinExchange::takeInfile(std::stringstream &ss, std::string filename)
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange::takeInfile()" << std::endl;
#endif
	std::string line;
	std::regex pattern(R"(^(\d{4}-\d{2}-\d{2})\s?\|\s?(\d+\.\d+|\d+)$)");
	std::smatch match;

	for (; std::getline(ss, line, '\n');)
	{
		if (std::regex_match(line, match, pattern) != true)
		{
			std::cerr << "error: " + filename + " contain faulty line \'"
					  << line << "\'" << std::endl;
			continue;
		}

		Date date(std::string(match[1].str()));
		std::map<Date, double>::const_iterator it = _map.upper_bound(date);
#ifdef TEST
		std::cout << "BTCE::takeInfile" << date << std::endl;
#endif
	}
}

//-------------------Orthodox Canonical Form-------------------//

BitcoinExchange::BitcoinExchange(std::stringstream &ss)
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange\tConstructor:\tstringstream"
			  << std::endl;
#endif
	std::string line;
	std::regex pattern(R"(^(\d{4}-\d{2}-\d{2}),(\d+\.\d+|\d+)$)");
	for (; std::getline(ss, line, '\n');)
	{
		if (std::regex_match(line, pattern) != true)
		{
			std::cerr << "error: data.csv contain faulty line \'" << line
					  << "\'" << std::endl;
			continue;
		}
		double value = std::strtod(line.substr(11).c_str(), NULL);
#ifdef TEST
		std::cout << "BTCE: line:\t" << line << "\t=> " << line.substr(0, 10)
				  << " - " << value << std::endl;
#endif
		_map.emplace(Date(line.substr(0, 10)), value);
	}
#ifdef TEST
	std::cout << "\nSHOW BITCOINEXCHANGE:\n";
	for (const auto &pair : _map)
		std::cout << "map:\t" << pair.first << "\t- " << pair.second << "\n";
	std::cout << std::endl;
#endif
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) : _map(rhs._map)
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange\tConstructor:\tcopy" << std::endl;
#endif
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange\tCopy Assignment Operator"
			  << std::endl;
#endif
	if (&rhs == this)
		return (*this);
	_map = rhs._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange\tDeconstructor" << std::endl;
#endif
}