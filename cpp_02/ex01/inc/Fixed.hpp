#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
	int _bit;
	static const int _fractional_bits = 8;

  public:
	Fixed();
	Fixed(const int inp);
	Fixed(const float inp);
	Fixed(const Fixed &inp);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float toFloat(void) const;
	int toint(void) const;

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
