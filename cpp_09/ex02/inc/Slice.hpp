#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>

template <typename Container>
class Slice
{
	typedef typename Container::value_type value_type;

  private:
	Container &_container;
	size_t _start;
	size_t _end;
	size_t _size;

  public:
	value_type &operator[](size_t index);
	Slice(Container &container);
	Slice(Container &container, size_t start, size_t end);
};

#include "Slice.tpp"

#endif // SLICE_HPP
