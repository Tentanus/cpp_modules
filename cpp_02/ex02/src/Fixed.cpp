
#include <Fixed.hpp>
#include <cmath>
#include <iostream>
#include <string>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;

	_bit = 0;
}

Fixed::Fixed(const int inp)
{
	std::cout << "Integer-Constructor called" << std::endl;

	_bit = inp << _fractionalbits;
}

Fixed::Fixed(const float inp)
{
	std::cout << "Float-Constructor called" << std::endl;

	_bit = (roundf(inp * (1 << _fractionalbits)));
}

Fixed::Fixed(const Fixed &inp)
{
	std::cout << "Copy Constructor called" << std::endl;
	_bit = inp._bit;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignement Operator called" << std::endl;
	if (this != &other)
		_bit = other._bit;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}
