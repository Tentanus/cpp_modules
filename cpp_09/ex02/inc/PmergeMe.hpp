#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <chrono>
#include <iostream>

#include "JacobSthalSequence.hpp"
#include "Slice.hpp"

#define FAILURE 1
#define SUCCESS 0

template <typename Container>
class PmergeMe
{
  private: // TODO: move variables to private
	Slice<Container> _numbers;
	size_t _pairs;
	size_t _pair_gap;
	bool _spare;
	PmergeMe *_parent;

  public:
	PmergeMe() = delete;
	PmergeMe(Container &numbers);
	PmergeMe(Slice<Container> &numbers);
	PmergeMe(const PmergeMe &rhs) = delete;
	PmergeMe &operator=(const PmergeMe &rhs) = delete;
	~PmergeMe();

	void sort();
	void recursive_sort();
	void swap(size_t idx, size_t idx_pair);
	void swapped(size_t idx, size_t idx_pair);

	void insertJacobSthal();

	size_t getPairs();
};

template <typename Container>
std::ostream &operator<<(std::ostream &os, const PmergeMe<Container> &merge);

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
