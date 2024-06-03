#include "Span.hpp"

void Span::addNumber(int value)
{
	if (_size == _index)
		throw SpanExceedSizeException(_size);
	_set.emplace(value);
	_index++;
}

void Span::addRange(int start, int end, int step)
{
	for (int i = start ; i < end ; i += step)
	{
		std::cout << "addNumber(" << std::to_string(i) << ")" << std::endl;
		try { addNumber(i);}
    	catch (Span::NoSpanException &e) {break;}
	}
}

int Span::longestSpan()
{
	if (_set.size() < 2)
		throw NoSpanException(_index);
	std::set<int>::iterator big = _set.begin();
	std::set<int>::iterator end = --_set.end();
	// std::cout << *big << "\t" << *end << std::endl;
	return (*end - *big);
}

int Span::shortestSpan()
{
	if (_set.size() < 2)
		throw NoSpanException(_index);
	int ret = INT_MAX;
	for (std::set<int>::iterator it = ++_set.begin() ;
		 it != _set.end() && ret != 1 ; it++) {
		/*
		std::cout << "\nround:\t" << std::to_string(*it) << std::endl;
		std::cout << "ret:\t" << std::to_string(ret) << std::endl;
		*/

		std::set<int>::iterator diff; 
		int tmp;
		diff = --it;
		it++;
		tmp = *it - *diff;
		// std::cout << "--:\t" << std::to_string(*it) << "\t" << std::to_string(*diff) << std::endl;
		if (tmp < ret)
			ret = tmp;
	}
	return (ret);
}

//-------------------Orthodox Canonical Form-------------------//

Span::Span(int size)
: _size(size), _index(0), _set()
{
	#ifdef MSG
		std::cout << "Called\tSpan\tConstructor:\tSized" << std::endl;
	#endif
}

Span::Span(const Span &rhs)
: _size(rhs._size), _index(rhs._index), _set(rhs._set)
{
	#ifdef MSG
		std::cout << "Called\tSpan\tConstructor:\tCopy" << std::endl;
	#endif
}

Span &Span::operator=(const Span &rhs)
{
	#ifdef MSG
		std::cout << "Called\tSpan\tCopy Assignment Operator" << std::endl;
	#endif
	if (this == &rhs)
		return (*this);
	_size = rhs._size;
	_index = rhs._index;
	_set = std::set<int>(rhs._set);
	return (*this);
}

Span::~Span()
{
	#ifdef MSG
		std::cout << "Called\tSpan\tDeconstructor" << std::endl;
	#endif
}
