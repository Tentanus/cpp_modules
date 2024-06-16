#ifndef SPAN_HPP
#define SPAN_HPP

#include <climits>
#include <exception>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Span
{
  private:
	int _size;
	int _index;
	std::set<int> _set;
	Span();

  public:
	Span(int size);
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int value);
	void merge(const Span &rhs);
	void addRange(int start, int end, int step);
	void addRange(const std::vector<int> &rhs);
	int shortestSpan(void);
	int longestSpan(void);

	class SpanExceedSizeException : public std::exception
	{
	  public:
		SpanExceedSizeException(int value)
		{
			std::ostringstream ss;
			ss << value;
			std::cerr << "Size of Span Exceeded [" << ss.str() << "]"
					  << std::endl;
		};
	};
	class NoSpanException : public std::exception
	{
	  public:
		NoSpanException(int index)
		{
			std::ostringstream ss;
			ss << index;
			std::cerr << "No Span possible, due to Span containing " << ss.str()
					  << " numbers." << std::endl;
		};
	};
};

#endif // !SPAN_HPP
