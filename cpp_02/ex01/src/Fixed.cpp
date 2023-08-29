
#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	_bit = 0;
}

Fixed::Fixed(const int inp)
{
	std::cout << "Integer-Constructor called" << std::endl;
	_bit = (int)inp << _fractional_bits & 0x7FFFFF00;
}

Fixed::Fixed(const float inp)
{
	std::cout << "Float-Constructor called" << std::endl;

	const int inp_bit = *(int *)&inp;

	// clang-format off
	_bit =	(inp_bit						& 0x80000000) +	// sign
			((int) inp << _fractional_bits	& 0x7FFFFF00) +	// before point
			(inp_bit >> 15					& 0x000000FF);	// after point
	// clang-format on
}

Fixed::Fixed(const Fixed &inp)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_bit = inp._bit;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	float ret = (_bit & 0x80000000 ? -1 : 1) * ();
	return ()
}

int Fixed::toint(void) const
{
	const int ret = (_bit & 0x80000000 ? -1 : 1) *
					((_bit & 0x7FFFFF00) >> _fractional_bits);
	return (ret);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits Method called" << std::endl;
	return (_bit);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Method called" << std::endl;
	_bit = raw;
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
