#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <chrono>
#include <iostream>

#include "Slice.hpp"

#define FAILURE 1
#define SUCCESS 0

template <typename Container>
class PmergeMe
{
  private:
	Slice<Container> _numbers;
	size_t _pairs;
	size_t _pair_gap;
	bool _spare;
	PmergeMe *_parent = NULL;

  public:
	PmergeMe() = delete;
	PmergeMe(Container numbers);
	PmergeMe(const PmergeMe &rhs) = delete;
	PmergeMe &operator=(const PmergeMe &rhs) = delete;
	~PmergeMe(){};

	void sort() {};
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
