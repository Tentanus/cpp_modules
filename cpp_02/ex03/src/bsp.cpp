
#include <Fixed.hpp>
#include <Point.hpp>

float absolute(float inp)
{
	if (inp < 0)
		return (-inp);
	return (inp);
}

float area_Triangle(const Point a, const Point b, const Point c)
{
	return (
		0.5 *
		(absolute(
			a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))));
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	(void)point;

	float a_ABC = area_Triangle(a, b, c);

	float a_ABP = area_Triangle(a, b, point);
	float a_ACP = area_Triangle(a, c, point);
	float a_BCP = area_Triangle(b, c, point);

	if ((a_ABP + a_BCP + a_ACP) == a_ABC)
	{
		std::cout << "Point: " << point << "\tis in triangle:\t\t" << a << b
				  << c << std::endl;
		return (true);
	}
	std::cout << "Point: " << point << "\tis NOT in triangle:\t" << a << b << c
			  << std::endl;
	return (false);
}
