#pragma once
#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

//-------------------Constructors-------------------//

template <typename Container>
PmergeMe<Container>::PmergeMe(Container numbers)
	: _numbers(numbers), _pairs(numbers.size() / 2),
	  _pair_gap((numbers.size() + 1) / 2), _spare(false){};

#endif // PMERGEME_TPP
