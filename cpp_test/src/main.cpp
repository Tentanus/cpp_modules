
#include <iostream>
#include <string>

int main()
{
	std::string				inp;
	std::string::size_type	sz;
	int						val;


	std::cout << std::endl << "Give detailed overview of Contact [1 - 8] or EXIT" << std::endl;
	std::getline(std::cin, inp);

	std::cout << "INPUT: " << inp <<  std::endl;

	if (inp == "EXIT")
		return (0);

	val = std::stoi(inp, &sz);
	std::cout << "val:\t" << val << std::endl << "sz:\t" << sz << std::endl;

	std::cout << "we are finished." << std::endl;
	return (0);

}
