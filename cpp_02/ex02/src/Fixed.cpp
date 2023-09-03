
#include <Fixed.hpp>
#include <cmath>
#include <iostream>
#include <string>

Fixed::Fixed()
{
#ifdef MSG
	std::cout << "Default Constructor called" << std::endl;
#endif

	_bit = 0;
}

Fixed::Fixed(const int inp)
{
#ifdef MSG
	std::cout << "Integer-Constructor called" << std::endl;
#endif

	_bit = inp << _fractionalbits;
}

Fixed::Fixed(const float inp)
{
#ifdef MSG
	std::cout << "Float-Constructor called" << std::endl;
#endif

	_bit = (roundf(inp * (1 << _fractionalbits)));
}

Fixed::Fixed(const Fixed &inp)
{
#ifdef MSG
	std::cout << "Copy Constructor called" << std::endl;
#endif

	_bit = inp._bit;
}

Fixed &Fixed::operator=(const Fixed &other)
{
#ifdef MSG
	std::cout << "Copy Assignement Operator called" << std::endl;
#endif

	if (this != &other)
		_bit = other._bit;
	return (*this);
}

Fixed::~Fixed()
{
#ifdef MSG
	std::cout << "Destructor called" << std::endl;
#endif
}

// Methods

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_bit) / (1 << _fractionalbits));
}

int Fixed::toInt(void) const
{
	return (_bit >> _fractionalbits);
}

int Fixed::getRawBits(void) const
{
	std::cout << " getRawBits Method called ";
	return (_bit);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Method called" << std::endl;
	_bit = raw;
}

std::string Fixed::showRawBits(void) const
{
	std::string str;
	for (size_t i = 0; i < (sizeof(int) * 8); i++)
		str += ((_bit >> (31 - i) & 0x1) ? "1" : "0");
	return (str);
}

// Operators
//		Comparisons ( == != < > <= >= )

bool Fixed::operator>(const Fixed &other) const
{
	return (_bit > other._bit);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_bit < other._bit);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_bit >= other._bit);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_bit <= other._bit);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_bit == other._bit);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_bit != other._bit);
}

//		Iterators ( ++ -- )

Fixed &Fixed::operator++(void)
{
	_bit += 1 << _fractionalbits;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	_bit -= 1 << _fractionalbits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	_bit += 1 << _fractionalbits;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	_bit -= 1 << _fractionalbits;
	return (tmp);
}

//		Other ( + - * / )

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed ans;

	ans._bit = _bit + other._bit;
	return (ans);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed ans;

	ans._bit = _bit - other._bit;
	return (ans);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	float prod;

	prod = static_cast<float>(_bit) * static_cast<float>(other._bit);
	Fixed ans(prod / (1 << (2 * _fractionalbits)));
	return (ans);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	float div;

	div = static_cast<float>(_bit) / static_cast<float>(other._bit);
	Fixed ans(div * (1 << (2 / _fractionalbits)));
	return (ans);
}

// Minimum / Maximum

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a._bit < b._bit ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a._bit < b._bit ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a._bit > b._bit ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a._bit > b._bit ? a : b);
}

// OS Stream operator overload;

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}
