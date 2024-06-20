#ifndef DATE_HPP

#include <string>

class Date {
	private:
		unsigned _year;
		unsigned _month;
		unsigned _day;

	public:
		Date() = delete;
		Date(const std::string inp);
		Date(const Date& rhs);
		Date &operator=(const Date& rhs);
		~Date();
		
};

#endif //!DATE_HPP