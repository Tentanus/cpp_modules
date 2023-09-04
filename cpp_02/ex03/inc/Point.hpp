#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include <Fixed.hpp>

// clang-format off
class Point 
{
  private:
	const Fixed	_x;
	const Fixed	_y;

	Point &operator=(Point &other);

  public:
	Point();
	Point(const float x_inp, const float y_inp);
	Point(const Point &inp);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};
// clang-format on

std::ostream &operator<<(std::ostream &os, const Point &inp);

#endif
