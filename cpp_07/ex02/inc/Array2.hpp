#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index Out Of Bounds Exception!!!!");
}

template <typename T>
T Array<T>::getArray(unsigned int idx) const
{
	if (idx >= _size)
		throw Array::OutOfBoundsException();
	return (_array[idx]);
}

template <typename T>
unsigned int Array<T>::getSize(void) const
{
	return (_size);
}

//----------------------Ostream Overload ----------------------//

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &ptr)
{
	std::cout << "Array:\n__size:\t\t" << ptr.getSize() << "\n__array:\t";
	for (size_t i = 0; i < ptr.getSize(); i++)
		std::cout << "[" << ptr.getArray(i) << "] ";
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

	_size = rhs.getSize();
	_array = new T[_size];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
}

template <typename T>
Array<T>::~Array()
{
#ifdef MSG
	std::cout << "Called Array Deconstructor" << std::endl;
#endif

	delete[] _array;
}

//----------------------Operator Overload ----------------------//

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
#ifdef MSG
	std::cout << "Called Array Assignment Operator" << std::endl;
#endif

	if (this == &rhs)
		return (rhs);

	delete[] _array;
	_size = rhs.getSize();
	_array = new T[_size];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int size)
{
#ifdef MSG
	std::cout << "Called Array Subscript Operator" << std::endl;
#endif
	if (size >= _size)
		throw Array::OutOfBoundsException();
	return (_array[size]);
}

#endif // !ARRAY_TPP
