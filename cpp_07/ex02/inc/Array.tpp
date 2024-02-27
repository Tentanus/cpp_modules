#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

//----------------------Ostream Overload ----------------------//

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &ptr)
{
	std::cout << "Array:\n__size:\t" << ptr._size << "\n__array:\t";
	for (size_t i = 0; i < ptr._size; i++)
		std::cout << "[" << ptr._array[i] << "] ";
	std::cout << std::endl;

	return (os);
}

//-------------------Orthodox Canonical Form-------------------//

template <typename T>
Array<T>::Array()
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tDefault" << std::endl;
#endif

	_size = 1;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int size)
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tSize" << std::endl;
#endif

	_size = size;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array<T> &rhs)
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tCopy" << std::endl;
#endif

	_size = rhs.size;
	_array = new T[_size];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
#ifdef MSG
	std::cout << "Called Array Assignment Operator" << std::endl;
#endif

	if (this == &rhs)
		return (rhs);

	delete[] _array;
	_size = rhs.size;
	_array = new T[_size];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
#ifdef MSG
	std::cout << "Called Array Deconstructor" << std::endl;
#endif

	delete[] _array;
}

#endif // !ARRAY_TPP
