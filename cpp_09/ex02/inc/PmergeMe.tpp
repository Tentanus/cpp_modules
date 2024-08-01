#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe<Container>::swapped(size_t idx, size_t idx_pair)
{
	swap(idx, idx_pair);
	if (_parent)
		_parent->swapped(idx + _pair_gap, idx_pair + _pair_gap);
}

template <typename Container>
void PmergeMe<Container>::swap(size_t idx, size_t idx_pair)
{
	size_t tmp = _numbers[idx];
	_numbers[idx] = _numbers[idx_pair];
	_numbers[idx_pair] = tmp;
	if (_parent)
		_parent->swapped(idx, idx_pair);
}

template <typename Container>
void PmergeMe<Container>::recursive_sort()
{
	Slice<Container> slice = _numbers.getSubSlice(_pair_gap);
	PmergeMe<Container> child(slice);

	if (child.getPairs() < 1)
		return;
	child._parent = this;
	child.sort();
}

template <typename Container>
void PmergeMe<Container>::sort()
{
#ifdef SHOW
	std::cout << *this << std::endl;
#endif
	for (size_t i = 0; i < _pairs; i++)
	{
		if (_numbers[i] > _numbers[i + _pair_gap])
			swap(i, i + _pair_gap);
	}
	recursive_sort();
#ifdef SHOW
	std::cout << *this << std::endl;
#endif
	insertJacobSthal();
}

template <typename Container>
size_t PmergeMe<Container>::insertJacobSthal()
{
}

//-------------------   Getters  -------------------//

template <typename Container>
size_t PmergeMe<Container>::getPairs()
{
	return (_pairs);
}

//-------------------  Utilities -------------------//

template <typename Container>
std::ostream &operator<<(std::ostream &os, const PmergeMe<Container> &merge)
{
	os << "PmergeMe [" << &merge << "]:\n";
	os << merge._numbers;
#ifdef VERB
	os << "pairs:  " << merge._pairs;
	os << "\ngap:    " << merge._pair_gap;
	os << "\nspare:  " << (merge._spare ? "YES" : "NO");
	os << "\nparent: ";
	if (merge._parent != nullptr)
		os << merge._parent;
	else
		os << "nullptr";
#endif
	os << std::endl;
	return (os);
}

//-------------------Constructors-------------------//

template <typename Container>
PmergeMe<Container>::PmergeMe(Container &numbers)
	: _numbers(numbers), _pairs(numbers.size() / 2),
	  _pair_gap((numbers.size() + 1) / 2), _spare(numbers.size() % 2 == 1),
	  _parent(nullptr)
{
#ifdef MSG
	std::cout << "Called\tConstructor [PMergeme]:\tContainer" << std::endl;
#endif
};

template <typename Container>
PmergeMe<Container>::PmergeMe(Slice<Container> &numbers)
	: _numbers(numbers), _pairs(numbers.getSize() / 2),
	  _pair_gap((numbers.getSize() + 1) / 2),
	  _spare(numbers.getSize() % 2 == 1), _parent(nullptr)
{
#ifdef MSG
	std::cout << "Called\tConstructor [PMergeme]:\tSlice" << std::endl;
#endif
};

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
#ifdef MSG
	std::cout << "Called\tDeconstructor [PMergeme]" << std::endl;
#endif
}
#endif // PMERGEME_TPP
