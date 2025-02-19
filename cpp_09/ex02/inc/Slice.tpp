#ifndef SLICE_TPP
#define SLICE_TPP

#include "Slice.hpp"
#include <typeinfo>

template <typename Container>
void Slice<Container>::erase(size_t idx)
{	
	typename Container::iterator it = _container.begin();
	std::advance(it, _start + idx);

	_container.erase(it);
}

template <typename Container>
void Slice<Container>::insert(size_t idx, typename Container::value_type val)
{
	typename Container::iterator it = _container.begin();
	std::advance(it, _start + idx);

	_container.insert(it, val);
	
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
	typename Container::iterator it = slice._container.begin();
	std::advance(it, slice._start);

	os << "  Slice: ";
	while(it != slice._container.end())
	{
		os << *it ;
		it++;
		if (it != slice._container.end())
			os << ", ";
	}
#ifdef VERB
	os << "\t_start:\t" << slice._start << "\n";
	os << "\t_end:\t" << slice._end << "\n";
	os << "\t_size:\t" << slice._size << std::endl;
#endif
	return (os);
}

template <typename Container>
typename Slice<Container>::value_type &
Slice<Container>::operator[](size_t index)
{
	typename Container::iterator it = _container.begin();
	std::advance(it, _start + index);

	return (*it);
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
