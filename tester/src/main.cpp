
#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include <sys/socket.h>

#include <tester.hpp>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	std::string str1 = "src";
	std::string str2 = "./src/main.cpp";
	bool val = std::filesystem::is_directory(str1);
	std::cout << "does " << str1 << " exist: " << (val ? "TRUE" : "FALSE")
			  << std::endl;
	val = std::filesystem::exists(str2);
	std::cout << "does " << str2 << " exist: " << (val ? "TRUE" : "FALSE")
			  << std::endl;
}

// You can compare Vector::iterators originating from the same
// vector
