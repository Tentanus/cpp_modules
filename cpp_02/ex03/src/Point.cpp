
#include <iostream>

#include <Fixed.hpp>
#include <Point.hpp>

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tDefault" << std::endl;
#endif
}

Point::Point(const float x_inp, const float y_inp) : _x(x_inp), _y(y_inp)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tfloat" << std::endl;
#endif
}

Point::Point(const Point &inp) : _x(inp._x), _y(inp._y)
{
#ifdef MSG
	std::cout << "Called\tConstructor:\tCopy" << std::endl;
#endif
}

Point::~Point()
{
#ifdef MSG
	std::cout << "Called\tDestructor:\tDefault" << std::endl;
#endif
}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

std::ostream &operator<<(std::ostream &os, const Point &inp)
{
	os << "( " << inp.getX() << " . " << inp.getY() << " )";

	return (os);
}
