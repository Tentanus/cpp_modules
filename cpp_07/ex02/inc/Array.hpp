#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
  public:
	Array();
	Array(unsigned int size);
	Array(const Array &rhs);
	Array<T> &operator=(const Array &rhs);

  private:
	T *_array;
	unsigned int _size;
};

#include "Array.tpp"

#endif // !ARRAY_HPP
