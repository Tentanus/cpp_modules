
#include <Harl.hpp>

int main()
{
	Harl harlslag;

	harlslag.complain("DEBUG");
	harlslag.complain("ERROR");
	harlslag.complain("INFO");
	harlslag.complain("WARNING");
	std::cout << "\n\tTEST: empty" << std::endl;
	harlslag.complain("");
	std::cout << "\n\tTEST: DEBUG" << std::endl;
	harlslag.complain("DEBUG");
	harlslag.complain("debug");
	harlslag.complain("DEBUg");
	harlslag.complain("DEBU");
	std::cout << "\n\tTEST: WARNING" << std::endl;
	harlslag.complain("WARNING");
	harlslag.complain("warning");
	harlslag.complain("WARNINg");
	harlslag.complain("WARNIN");
	std::cout << "\n\tTEST: TEST ME" << std::endl;
}
