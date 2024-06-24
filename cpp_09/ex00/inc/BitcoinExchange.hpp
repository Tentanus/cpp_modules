#ifndef BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Date.hpp"

class BitcoinExchange
{
  private:
	std::map<Date, double> _map;

  public:
	BitcoinExchange(std::stringstream &ss);
	BitcoinExchange() = delete;
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void takeInfile(std::stringstream &ss);
};

#endif //! BITCOINEXCHANGE_HPP
