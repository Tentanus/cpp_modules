#include "Span.hpp"
#include <string>

int main(void)
{
	Span spn(5);

	spn.addNumber(1000);
	try
	{
		// spn.addNumber(11);
		// spn.addNumber(-1);
		// spn.addNumber(111);
		// spn.addNumber(200);
		// spn.addNumber(1516);
	}
	catch (Span::SpanExceedSizeException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "longest:\t" << std::to_string(spn.longestSpan())
				  << std::endl;
		std::cout << "shortest:\t" << std::to_string(spn.shortestSpan())
				  << std::endl;
	}
	catch (Span::NoSpanException &e)
	{	
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
