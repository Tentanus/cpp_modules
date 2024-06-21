#ifndef DATE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Date
{
  private:
	unsigned int _year;
	unsigned int _month;
	unsigned int _day;

  public:
	Date() = delete;
	Date(const std::string inp);
	Date(const Date &rhs);
	Date &operator=(const Date &rhs);
	~Date();

	const std::string getDate(void) const;

	bool operator==(const Date &rhs) const;
	bool operator<(const Date &rhs) const;
};
std::ostream &operator<<(std::ostream &os, const Date &date);

#endif //! DATE_HPP