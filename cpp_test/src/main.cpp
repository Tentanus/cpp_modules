
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	std::string				inp;
//	std::string::size_type	sz;
//	int						val_stoi;
	int						val_atoi;


	std::cout << std::endl << "Give detailed overview of Contact [1 - 8] or EXIT" << std::endl;
	std::getline(std::cin, inp);

	std::cout << "INPUT: " << inp <<  std::endl;

	if (inp == "EXIT")
		return (0);

	val_atoi = std::atoi(inp.c_str());
	std::cout << "val atoi:\t" << val_atoi << std::endl;

//	val_stoi = std::stoi(inp, &sz);
//	std::cout << "val:\t" << val_stoi << std::endl << "sz:\t" << sz << std::endl;

	std::cout << "we are finished." << std::endl;
	return (0);

}
