#include "Slice.hpp"

template <typename Container>
typename Slice<Container>::value_type &
Slice<Container>::operator[](size_t index)
{
	return (_container[_start + index]);
}
