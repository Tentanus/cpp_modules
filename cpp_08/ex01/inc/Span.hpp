#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <sstream>
# include <set>
# include <iterator>
# include <climits>
# include <string>

class Span {
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
	void addRange(int start, int end, int step);
	int shortestSpan(void);
	int longestSpan(void);

	class SpanExceedSizeException : public std::exception {
		public:
		SpanExceedSizeException(int value) 
		{
			std::ostringstream ss;
			ss << value;
			std::cerr << "Size of Span Exceeded [" << ss.str() << "]" << std::endl;	
		};
	};
	class NoSpanException : public std::exception {
		public:
		NoSpanException(int index) {
			std::ostringstream ss;
			ss << index;
			std::cerr << "No Span possible, due to Span containing " << ss.str() << " numbers." << std::endl;
		};
	};
};

#endif // !SPAN_HPP
