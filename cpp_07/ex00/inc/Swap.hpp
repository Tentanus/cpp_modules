#ifndef SWAP_HPP
#define SWAP_HPP

#include <iostream>

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

#endif // !SWAP_HPP
