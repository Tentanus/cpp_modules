#ifndef SLICE_TPP
#define SLICE_TPP

#include "Slice.hpp"

template <typename Container>
void Slice<Container>::erase(size_t idx)
{
	_container.erase(_container.begin() + _start + idx);
}

template <typename Container>
void Slice<Container>::insert(size_t idx, typename Container::value_type val)
{
	_container.insert(_container.begin() + _start + idx, val);
}

//-------------------   Getters  -------------------//

template <typename Container>
size_t Slice<Container>::getSize()
{
	return (_size);
}

template <typename Container>
size_t Slice<Container>::getSpare()
{
	return (_spare);
}

//-------------------  Utilities -------------------//

template <typename Container>
Slice<Container> Slice<Container>::getSubSlice(size_t gap)
{
	if (gap > _size)
		throw std::out_of_range("getSubSlice: new start > _size of slice");
	return (Slice<Container>(_container, _start + gap, _end));
}

template <typename Container>
std::ostream &operator<<(std::ostream &os, const Slice<Container> &slice)
{
	os << "\tSlice: ";
	for (typename Container::iterator nbr =
			 slice._container.begin() + slice._start;
		 nbr != slice._container.end(); nbr++)
	{
		os << *nbr << ", ";
	}
#ifdef VERB
	os << "\t_start:\t" << slice._start;
	os << "\n\t_end:\t" << slice._end;
	os << "\n\t_size:\t" << slice._size << std::endl;
#endif
	//	os << std::endl;
	return (os);
}

template <typename Container>
typename Slice<Container>::value_type &
Slice<Container>::operator[](size_t index)
{
	return (_container[_start + index]);
}

//-------------------Constructors-------------------//

template <typename Container>
Slice<Container>::Slice(Container &container)
	: _container(container), _start(0), _end(container.size()), _size(_end),
	  _spare(_size % 2)
{
#ifdef MSG
	std::cout << "Called\tConstructor [Slice]:\tContainer" << std::endl;
#endif
}

template <typename Container>
Slice<Container>::Slice(Container &container, size_t start, size_t end)
	: _container(container), _start(start), _end(end), _size(end - start),
	  _spare(_size % 2)
{
#ifdef MSG
	std::cout << "Called\tConstructor [Slice]:\tSubSlice" << std::endl;
#endif
}

template <typename Container>
Slice<Container>::~Slice()
{
#ifdef MSG
	std::cout << "Called\tDeconstructor [Slice]" << std::endl;
#endif
}

#endif // SLICE_TPP
