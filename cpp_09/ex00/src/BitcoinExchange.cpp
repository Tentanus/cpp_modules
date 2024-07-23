#include "BitcoinExchange.hpp"

void BitcoinExchange::takeInfile(std::stringstream &ss)
{
#ifdef MSG
	std::cout << "Called\tBitcoinExchange::takeInfile()" << std::endl;
#endif
	std::string line;
	std::regex pattern(R"(^(\d{4}-\d{2}-\d{2})\s?\|\s?(\d+\.\d+|\d+)$)");
	std::smatch match;

	for (; std::getline(ss, line, '\n');)
	{
		try
		{
			if (line.empty())
				continue;
			if (std::regex_match(line, match, pattern) != true)
				throw std::runtime_error("contains faulty line \'" + line +
										 "\'");

			Date date(std::string(match[1].str()));
			double amount = std::strtod(match[2].str().c_str(), NULL);
			if (amount < 0)
				throw std::runtime_error("non-positive amount: " +
										 match[2].str());
			else if (amount > 1000)
				throw std::runtime_error("too large a number: " +
										 match[2].str());

#ifdef TEST
			std::cout << "BTCE::takeInfile\t" << date << " " << amount
					  << std::endl;
#endif
			std::map<Date, double>::const_iterator it = _map.upper_bound(date);
			if (it == _map.begin())
				throw std::runtime_error("no data before " + date.getDate());
			it--;
			double result = it->second * amount;
			std::cout << date << " => " << amount << " = " << result
					  << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
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
		try
		{
			line = line.substr(0, line.find_first_of('#'));
			if (line.empty())
				continue;
			if (std::regex_match(line, pattern) != true)
				throw std::runtime_error("data.csv contain faulty line \'" +
										 line + "\'");
			double value = std::strtod(line.substr(11).c_str(), NULL);
			Date date(line.substr(0, 10));

#ifdef TEST
			std::cout << "BTCE: line:\t" << line << "\t=> "
					  << line.substr(0, 10) << " - " << value << std::endl;
#endif

			_map.emplace(date, value);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
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
