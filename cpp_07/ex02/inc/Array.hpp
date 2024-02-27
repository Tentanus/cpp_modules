#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <climits>
#include <iostream>
#include <string>

template <typename T>
class Array
{
  public:
	Array();
	Array(unsigned int size);
	Array(const Array &rhs);
	Array<T> &operator=(const Array &rhs);
	~Array();

  private:
	T *_array;
	unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &ptr);

#include "Array.tpp"

#endif // !ARRAY_HPP
