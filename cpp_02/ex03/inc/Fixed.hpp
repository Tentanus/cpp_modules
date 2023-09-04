#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

// clang-format off
class Fixed
{
  private:
	int					_bit;
	static const int	_fractionalbits = 8;

  public:
	Fixed();
	Fixed(const int inp);
	Fixed(const float inp);
	Fixed(const Fixed &inp);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float				toFloat(void) const;
	int					toInt(void) const;

	int					getRawBits(void) const;
	void				setRawBits(const int raw);
	std::string			showRawBits(void) const;

	bool				operator>(const Fixed &other) const;
	bool				operator<(const Fixed &other) const;
	bool				operator>=(const Fixed &other) const;
	bool				operator<=(const Fixed &other) const;
	bool				operator==(const Fixed &other) const;
	bool				operator!=(const Fixed &other) const;

	Fixed				&operator++(void);
	Fixed				&operator--(void);
	Fixed				operator++(int);
	Fixed				operator--(int);

	Fixed				operator+(const Fixed &other) const;
	Fixed				operator-(const Fixed &other) const;
	Fixed				operator*(const Fixed &other) const;
	Fixed				operator/(const Fixed &other) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);
// clang-format on

#endif
