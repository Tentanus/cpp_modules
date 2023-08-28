
#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &inp)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = inp._value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignement Operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits Method called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Method called" << std::endl;
	_value = raw;
}
