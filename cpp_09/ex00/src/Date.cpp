#include "Date.hpp"

bool Date::operator==(const Date &rhs) const
{
	return (_year == rhs._year && _month == rhs._month && _day == rhs._day);
}

bool Date::operator<(const Date &rhs) const
{
	if (_year != rhs._year)
	{
		return (_year < rhs._year);
	}
	if (_month != rhs._month)
	{
		return (_month < rhs._month);
	}
	return (_day < rhs._day);
}

const std::string Date::getDate(void) const
{
	return (std::to_string(_year) + "-" + std::to_string(_month) + "-" +
			std::to_string(_day));
}

std::ostream &operator<<(std::ostream &os, const Date &date)
{
	os << date.getDate();
	return (os);
}

//-------------------Orthodox Canonical Form-------------------//

Date::Date(const std::string inp)
{
#ifdef MSG
	std::cout << "Called\tDate\tConstructor:\tString" << std::endl;
#endif
#ifdef TEST
	std::cout << " Date::string:\t\t" << inp << std::endl;
#endif
	char *endptr;
	_year = strtoul(inp.c_str(), &endptr, 10);
	endptr++;
	_month = strtoul(endptr, &endptr, 10);
	endptr++;
	_day = strtoul(endptr, NULL, 10);
	endptr++;

	if (_year < 1)
		throw std::runtime_error("invalid date: " + inp);
	if (_month > 12 || _month < 1)
		throw std::runtime_error("invalid date: " + inp);

	unsigned int days_in_month[12] = {31, 29, 31, 30, 31, 30,
									  31, 31, 30, 31, 30, 31};
	if (_day > days_in_month[_month - 1] || _day < 1)
		throw std::runtime_error("invalid date: " + inp);

	if (_month == 2 && _day > 28 &&
		!(_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)))
		throw std::runtime_error("invalid date no-leap year: " + inp);

#ifdef TEST
	std::cout << " Date::double:\t\t" << _year << " " << _month << " " << _day
			  << " " << std::endl;
#endif
}

Date::Date(const Date &rhs)
	: _year(rhs._year), _month(rhs._month), _day(rhs._day)
{
#ifdef MSG
	std::cout << "Called\tDate\tConstructor:\tCopy" << std::endl;
#endif
}

Date &Date::operator=(const Date &rhs)
{
#ifdef MSG
	std::cout << "Called\tDate\tCopy Assignment Operator" << std::endl;
#endif
	if (&rhs == this)
		return (*this);
	_year = rhs._year;
	_month = rhs._month;
	_day = rhs._day;
	return (*this);
}

Date::~Date()
{
#ifdef MSG
	std::cout << "Called\tDate\tDeconstructor" << std::endl;
#endif
}
