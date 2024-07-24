#pragma once
#ifndef SLICE_TPP
#define SLICE_TPP

#include "Slice.hpp"

//-------------------Constructors-------------------//

template <typename Container>
Slice<Container>::Slice(Container &container)
	: _container(container), _start(0), _end(container.size()), _size(_end)
{
}

template <typename Container>
Slice<Container>::Slice(Container &container, size_t start, size_t end)
	: _container(container), _size(end - start), _start(start), _end(end)
{
}

#endif // SLICE_TPP
