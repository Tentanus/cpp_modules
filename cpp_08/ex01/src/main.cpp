#include "Span.hpp"
#include <string>

int main(void)
{
	Span spn(4);
	spn.addRange(3, 8, 2);
	try
	{
		spn.addNumber(11);
	}
	catch (Span::SpanExceedSizeException &e)
	{
	}

	try
	{
		std::cout << "longest:\t" << std::to_string(spn.longestSpan())
				  << std::endl;
	}
	catch (Span::NoSpanException &e)
	{
	}

	try
	{
		std::cout << "shortest:\t" << std::to_string(spn.shortestSpan())
				  << std::endl;
	}
	catch (Span::NoSpanException &e)
	{
	}

	return (0);
}
