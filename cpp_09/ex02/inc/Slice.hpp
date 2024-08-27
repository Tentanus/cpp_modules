#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename Container>
class Slice
{
	typedef typename Container::value_type value_type;

  private: // TODO: move variables to private
  public:
	Container &_container;
	size_t _start;
	size_t _end;
	size_t _size;
	bool _spare;

	Slice(Container &container);
	Slice(Container &container, size_t start, size_t end);
	~Slice();

	void erase(size_t idx);
	void insert(size_t idx, typename Container::value_type val);

	size_t getSpare();
	size_t getSize();

	Slice<Container> getSubSlice(size_t gap);
	value_type &operator[](size_t index);
};

template <typename Container>
std::ostream &operator<<(std::ostream &os, const Slice<Container> &slice);

#include "Slice.tpp"

#endif // SLICE_HPP
