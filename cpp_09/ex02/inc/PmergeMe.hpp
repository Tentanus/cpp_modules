#ifndef PMERGEME_HPP

#include <chrono>
#include <iostream>
#include <list>
#include <vector>

#define FAILURE 1
#define SUCCESS 0

template <typename Container>
class PmergeMe
{
  private:
	Container &numbers;

  public:
	PmergeMe() = delete;
	PmergeMe(Container &numbers) : numbers(numbers){};
	PmergeMe(const PmergeMe &rhs) = delete;
	PmergeMe &operator=(const PmergeMe &rhs) = delete;
	~PmergeMe(){};

	void sort() {};
};

#endif // PMERGEME_HPP
