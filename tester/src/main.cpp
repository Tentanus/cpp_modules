
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

#include <errno.h>
#include <stdint.h>
#include <string.h>

#include <dirent.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <tester.hpp>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	std::string str1 = "src";
	bool val = std::filesystem::is_directory(str1);
	std::cout << "does " << str1 << " exist: " << (val ? "TRUE" : "FALSE")
			  << std::endl;

	std::string path = "./src";
	DIR *dir = opendir(path.c_str());
	struct dirent *dp;
	std::filesystem::path pwd = std::filesystem::current_path();

	while ((dp = readdir(dir)) != NULL)
	{
		std::string path = pwd.string();
		std::string filepath = path + "/src/" + dp->d_name;

		struct stat filestat;
		if (stat(filepath.c_str(), &filestat) == -1)
		{
			std::cout << "NO STAT\t" << filepath << "\t"
					  << std::string(strerror(errno)) << "\n";
			continue;
		}
		std::cout << std::to_string((intmax_t)filestat.st_size) << "\t"
				  << sizeof(filestat.st_size) << "\t" << filepath << std::endl;
	}
}

// I don't get why i can't use stat to find the size wtf.

// You can compare Vector::iterators originating from the same
// vector
