#include "JacobSthalSequence.hpp"
#include "PmergeMe.hpp"

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

//-------------------   Operations  -------------------//

template <typename Container>
void PmergeMe<Container>::move(size_t from, size_t to)
{
	if (from == to)
		return;
	if (from >= _numbers.getSize() || to >= _numbers.getSize())
		return;

	typename Container::value_type tmp = _numbers[from];
	_numbers.erase(from);
	_numbers.insert(to + (from > to), tmp);

#ifdef SHOW_OPP
	std::cout << "move     :  " << *this << std::endl;
#endif
	if (_parent)
		_parent->moved(from, to);
}

template <typename Container>
void PmergeMe<Container>::moved(size_t from, size_t to)
{
	move(from, to);
	if (_parent)
		_parent->moved(from + _pair_gap, to + _pair_gap);

#ifdef SHOW
	std::cout << "moved    :  " << *this << std::endl;
#endif
}

template <typename Container>
void PmergeMe<Container>::swap(size_t idx, size_t idx_pair)
{
	size_t tmp = _numbers[idx];
	_numbers[idx] = _numbers[idx_pair];
	_numbers[idx_pair] = tmp;

#ifdef SHOW_OPP
	std::cout << "swap     :  " << *this << std::endl;
#endif
	if (_parent)
		_parent->swapped(idx, idx_pair);

}

template <typename Container>
void PmergeMe<Container>::swapped(size_t idx, size_t idx_pair)
{
	swap(idx, idx_pair);
	if (_parent)
		_parent->swapped(idx + _pair_gap, idx_pair + _pair_gap);

#ifdef SHOW
	std::cout << "swapped  :  " << *this << std::endl;
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

//-------------------   Algorithm Helpers  -------------------//

// NOTE: end is exclusive
template <typename Container>
size_t PmergeMe<Container>::findInsertSpot(typename Container::value_type value, size_t start, size_t end)
{
	while (start != end) {
		size_t mid = (start + end) / 2;
		if (value > _numbers[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return (start);
}

template <typename Container>
void PmergeMe<Container>::insertJacobSthal()
{
	size_t to_insert = _pair_gap;
	move(0, _pair_gap - 1);
	to_insert--;
#ifdef SHOW
	std::cout << "mijs 1st :  " << *this << std::endl;
#endif
	JacobSthalSequence seq;

	while (to_insert > _numbers.getSpare()) {
		size_t already_inserted = _pair_gap - to_insert;
		size_t jacob = seq.next();
		size_t max_group_size = to_insert - _numbers.getSpare();
		size_t group_size = jacob < max_group_size ? jacob : max_group_size;
		size_t search_size = already_inserted * 2 + group_size - 1;
		for (size_t i = group_size; i > 0 ; i--)
		{
			size_t spot = findInsertSpot(_numbers[i - 1], to_insert, to_insert + search_size);
			move(i - 1, spot - 1);
			to_insert--;
#ifdef SHOW
			std::cout << "mijs MeIn:  " << *this << "[" << spot - 1 <<"]" << std::endl;
#endif
		}
	}
	if (to_insert) {
		size_t spot = findInsertSpot(_numbers[0], 1, _numbers.getSize());
		move(0, spot - 1);
#ifdef SHOW
		std::cout << "mijs left:  " << *this << "[" << spot - 1 <<"]" << std::endl;
#endif
	}

	return ;
}

//-------------------   Sort  -------------------//

template <typename Container>
void PmergeMe<Container>::sort()
{
#ifdef SHOW
	std::cout << "sort init:  " << *this << std::endl;
#endif

	for (size_t i = 0; i < _pairs; i++)
	{
		if (_numbers[i] > _numbers[i + _pair_gap])
			swap(i, i + _pair_gap);
	}
#ifdef SHOW
	std::cout << "sort swap:  " << *this << "\n" << std::endl;
#endif

	recursive_sort();
#ifdef SHOW
	std::cout << "sort recs:  " << *this << std::endl;
#endif

	insertJacobSthal();
#ifdef SHOW
	std::cout << "sort post:  " << *this << "\n" << std::endl;
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
	os << "PmergeMe [" << merge.getLayer() << "]: ";
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
