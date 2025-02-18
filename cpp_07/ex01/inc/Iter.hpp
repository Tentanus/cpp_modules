#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
T &min(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called min: ";
#endif
	return (a <= b ? a : b);
}

template <typename T>
T &max(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called max: ";
#endif
	return (a >= b ? a : b);
}

template <typename T>
void swap(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called swap: ";
#endif
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T mult(const T a)
{
#ifdef MSG
	std::cout << "Called mult\n";
#endif
	return (a * 2);
}

template <typename T>
T capital(const T val)
{
#ifdef MSG
	std::cout << "Called capital\n";
#endif
	if (val.empty()) return T("");
	T tmp = val;
	tmp[0] = toupper(val[0]);
	return tmp;
}

template <typename T>
void iter(T *ptr, size_t n, T(f)(const T))
{
#ifdef MSG
	std::cout << "Called iter\n";
#endif
	for (size_t i = 0; i < n; i++)
	{
		ptr[i] = f(ptr[i]);
	}
}

#endif // !ITER_HPP
