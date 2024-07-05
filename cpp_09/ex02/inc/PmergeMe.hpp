#ifndef PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>

#

class PmergeMe
{
  private:
	char **argv;

  public:
	PmergeMe() = delete;
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();
};

#endif // PMERGEME_HPP
