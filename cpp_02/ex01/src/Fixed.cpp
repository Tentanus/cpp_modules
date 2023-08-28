
#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	_fixedvalue = 0;
}

Fixed::Fixed(const int inp)
{
	std::cout << "Integer-Constructor called" << std::endl;
	_fixedvalue = inp << _fractional_bits;
}

Fixed::Fixed(const float inp)
{
	std::cout << "Float-Constructor called" << std::endl;
	_fixedvalue;
}

Fixed::Fixed(const Fixed &inp)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_fixedvalue = inp._fixedvalue;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignement Operator called" << std::endl;
	if (this != &other)
		_fixedvalue = other._value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits Method called" << std::endl;
	return (_fixedvalue);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Method called" << std::endl;
	_fixedvalue = raw;
}
