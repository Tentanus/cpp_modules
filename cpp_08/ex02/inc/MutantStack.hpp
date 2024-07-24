#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

  public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;

	/*
		OFC is inherited from std::stack<T>

		MutantStack();
		MutantStack(const MutantStack &rhs);
		MutantStack &operator=(const MutantStack &rhs);
		~MutantStack();
	//*/
};

#include "MutantStack.tpp"
#endif // !MUTANTSTACK_HPP
