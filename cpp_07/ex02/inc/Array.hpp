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

	T &operator[](unsigned int size);
	unsigned int getSize(void) const;
	T getArray(unsigned int idx) const;

  private:
	T *_array;
	unsigned int _size;

	class OutOfBoundsException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &ptr);

#include "Array.tpp"

#endif // !ARRAY_HPP
