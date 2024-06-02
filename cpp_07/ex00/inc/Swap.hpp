#ifndef SWAP_HPP
#define SWAP_HPP

#include <iostream>

template <typename T>
T &min(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called min\n";
#endif
	return (a <= b ? a : b);
}

template <typename T>
T &max(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called max\n";
#endif
	return (a >= b ? a : b);
}

template <typename T>
void swap(T &a, T &b)
{
#ifdef MSG
	std::cout << "Called swap\n";
#endif
	T tmp = a;
	a = b;
	b = tmp;
}

#endif // !SWAP_HPP
