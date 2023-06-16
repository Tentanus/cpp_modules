#include <iostream>

std::string str_to_upper(std::string str) {
	int		strlen = str.length();

	for (int i = 0; i < strlen; i++) {
		if (islower(str[i]))
			str[i] = toupper(str[i]);
	}

	return (str);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::cout << str_to_upper(argv[i]) << " ";
	}
	std::cout << std::endl;
	return (0);
}
