
#include <iostream>

#include <Fixed.hpp>
#include <Point.hpp>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	Point A(0, 0);
	Point B(0, 5);
	Point C(5, 0);

	Point p_01(1, 1);
	Point p_02(5, 5);
	Point p_03(3, 0);
	Point p_04(0, 5.01);
	Point p_05(3, 3);

	bsp(A, B, C, p_01);
	bsp(A, B, C, p_02);
	bsp(A, B, C, p_03);
	bsp(A, B, C, p_04);
	bsp(A, B, C, p_05);
}
