#include "JacobSthalSequence.hpp"
#include "PmergeMe.hpp"

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template <typename Container>
void PmergeMe<Container>::moved(size_t from, size_t to)
{
	move(from, to);
	if (_parent)
		_parent->moved(from + _pair_gap, to + _pair_gap);
}

template <typename Container>
void PmergeMe<Container>::move(size_t from, size_t to)
{
	if (from == to)
		return;
	if (from >= _numbers.getSize() || to >= _numbers.getSize())
		return;

#ifdef SHOW_OPP
	std::cout << "MOVE PRE:\n" << *this << std::endl;
#endif
	typename Container::value_type tmp = _numbers[from];
	_numbers.erase(from);
	_numbers.insert(to + (from > to), tmp);

	// TODO: why is the _parent moved still required?
	if (_parent)
		_parent->moved(from, to);

#ifdef SHOW_OPP
	std::cout << "MOVE POST:\n" << *this << "\n" << std::endl;
#endif
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
	std::cout << "SORT INIT:\n" << *this << std::endl;
#endif
	for (size_t i = 0; i < _pairs; i++)
	{
		if (_numbers[i] > _numbers[i + _pair_gap])
			swap(i, i + _pair_gap);
	}

#ifdef SHOW
	std::cout << "SORT SINGLE SORT:\n" << *this << std::endl;
#endif

	recursive_sort();

#ifdef SHOW
	std::cout << "SORT REC SORT:\n" << *this << std::endl;
#endif

	insertJacobSthal();
#ifdef SHOW
	std::cout << "SORT POST:\n" << *this << "\n" << std::endl;
#endif
}

template <typename Container>
void PmergeMe<Container>::swap(size_t idx, size_t idx_pair)
{
#ifdef SHOW_OPP
	std::cout << "SWAP PRE:\n" << *this << std::endl;
#endif
	size_t tmp = _numbers[idx];
	_numbers[idx] = _numbers[idx_pair];
	_numbers[idx_pair] = tmp;

	if (_parent)
		_parent->swapped(idx, idx_pair);
#ifdef SHOW_OPP
	std::cout << "SWAP POST:\n" << *this << "\n" << std::endl;
#endif
}

template <typename Container>
void PmergeMe<Container>::swapped(size_t idx, size_t idx_pair)
{
	swap(idx, idx_pair);

	if (_parent)
		_parent->swapped(idx + _pair_gap, idx_pair + _pair_gap);
}

#ifdef SHOW
	std::cout << "SWAP POST:\n" << *this << std::endl;
#endif
}

//-------------------   Getters  -------------------//

template <typename Container>
size_t PmergeMe<Container>::getLayer() const
{
	if (_parent == nullptr)
		return (0);
	else
		return (_parent->getLayer() + 1);
}

template <typename Container>
size_t PmergeMe<Container>::getPairs() const
{
	return (_pairs);
}

//-------------------  Utilities -------------------//

template <typename Container>
std::ostream &operator<<(std::ostream &os, const PmergeMe<Container> &merge)
{
	os << "  PmergeMe [" << merge.getLayer() << "]:\t";
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
	//	os << std::endl;
	return (os);
}

//-------------------Constructors-------------------//

template <typename Container>
PmergeMe<Container>::PmergeMe(Container &numbers)
	: _numbers(numbers), _pairs(numbers.size() / 2),
	  _pair_gap((numbers.size() + 1) / 2), _parent(nullptr)
{
#ifdef MSG
	std::cout << "Called\tConstructor [PMergeme]:\tContainer" << std::endl;
#endif
};

template <typename Container>
PmergeMe<Container>::PmergeMe(Slice<Container> &numbers)
	: _numbers(numbers), _pairs(numbers.getSize() / 2),
	  _pair_gap((numbers.getSize() + 1) / 2), _parent(nullptr)
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
