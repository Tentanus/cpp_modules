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
	unsigned int _size;
	unsigned int _index;
	std::set<int> _set;
	Span();

  public:
	Span(unsigned int size);
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int value);
	void merge(const Span &rhs);
	void addRange(int start, int end, int step);
	void addRange(const std::vector<int> &rhs);
	int shortestSpan(void);
	int longestSpan(void);

	class NoSpanException : public std::exception
	{
	private:
    	std::string message;

	public:
	    explicit NoSpanException(int size) {
			std::ostringstream ss;
			ss  << "No Span possible, due to Span containing " 
				<< size << " numbers.";
			message = ss.str();
		};
	
	    const char* what() const noexcept override {
	        return message.c_str();
	    }
	};

	class SpanExceedSizeException : public std::exception	{
	  private:
    	std::string message;

	  public:
	    explicit SpanExceedSizeException(int index) {
	        std::ostringstream ss;
			ss << "Size of Span Exceeded [" << index << "]";
	        message = ss.str();
	    }
	
	    const char* what() const noexcept override {
	        return message.c_str();
	    }
	};
};

#endif // !SPAN_HPP
