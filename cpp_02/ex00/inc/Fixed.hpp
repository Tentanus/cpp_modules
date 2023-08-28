#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
  private:
	int _value;
	static const int _fractional_bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &inp);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

#endif
