#include "Span.hpp"

void Span::addNumber(int value)
{
	if (_size == _index)
		throw SpanExceedSizeException(_size);
#ifdef MSG
	std::cout << "Span:\taddNumber(" << std::to_string(value) << ")"
			  << std::endl;
#endif
	_set.emplace(value);
	_index++;
}

void Span::addRange(const std::vector<int> &rhs)
{
#ifdef MSG
	std::cout << "Span:\taddRange(Vector)" << std::endl;
#endif
	if (_index + rhs.size() > static_cast<size_t>(_index))
		throw SpanExceedSizeException(_index + rhs.size());
	_set.insert(rhs.begin(), rhs.end());
}

void Span::addRange(int start, int end, int step)
{
#ifdef MSG
	std::cout << "Span:\taddRange(" << start << ", " << end << ", " << step
			  << ")" << std::endl;
#endif
	for (int i = start; i < end; i += step)
	{
		try
		{
			addNumber(i);
		}
		catch (Span::NoSpanException &e)
		{
			break;
		}
	}
}

void Span::merge(const Span &rhs)
{
#ifdef MSG
	std::cout << "Span:\tmerge()" << std::endl;
#endif
	if (_index + rhs._size > _index)
		throw SpanExceedSizeException(_index + rhs._size);
	for (int nbr : rhs._set)
	{
		_set.emplace(nbr);
	}
}

// constant
int Span::longestSpan()
{
	if (_set.size() < 2)
		throw NoSpanException(_index);
	std::set<int>::iterator big = _set.begin();
	std::set<int>::iterator end = --_set.end();
	return (*end - *big);
}

// O(N)
int Span::shortestSpan()
{
	if (_set.size() < 2)
		throw NoSpanException(_index);
	int ret = INT_MAX;
	for (std::set<int>::iterator it = ++_set.begin();
		 it != _set.end() && ret != 1; it++)
	{
		std::set<int>::iterator diff;
		int tmp;
		diff = --it;
		it++;
		tmp = *it - *diff;
		/*
		#ifdef MSG
				std::cout << "\ndiff:\t" << std::to_string(*diff) << " "
						  << std::to_string(*it) << "\t| " <<
		std::to_string(tmp); #endif
//		*/
		if (tmp < ret)
			ret = tmp;
	}
#ifdef MSG
	std::cout << std::endl;
#endif
	return (ret);
}

//-------------------Orthodox Canonical Form-------------------//

Span::Span(int size) : _size(size), _index(0), _set()
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
