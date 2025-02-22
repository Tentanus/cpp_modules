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
  private:
	PmergeMe() = delete;
	PmergeMe(const PmergeMe &rhs) = delete;
	PmergeMe &operator=(const PmergeMe &rhs) = delete;

  public:
	Slice<Container> _numbers;
	size_t _pairs;
	size_t _pair_gap;
	PmergeMe *_parent;

	PmergeMe(Container &numbers);
	PmergeMe(Slice<Container> &numbers);
	~PmergeMe();

	void move(size_t from, size_t to);
	void moved(size_t from, size_t to);
	void sort();
	void recursive_sort();
	void swap(size_t idx, size_t idx_pair);
	void swapped(size_t idx, size_t idx_pair);


	void insertJacobSthal();
	size_t findInsertSpot(typename Container::value_type value, size_t start,
						 size_t end);

	size_t getPairs() const;
	size_t getLayer() const;
};

template <typename Container>
std::ostream &operator<<(std::ostream &os, const PmergeMe<Container> &merge);

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
