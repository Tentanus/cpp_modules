#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
  private:
	int _bit;
	static const int _fractionalbits = 8;

  public:
	Fixed();
	Fixed(const int inp);
	Fixed(const float inp);
	Fixed(const Fixed &inp);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	/*
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
	*/
	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(const int raw);
	std::string showRawBits(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif
