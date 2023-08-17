
#include <fstream>
#include <iostream>

typedef enum e_errcode
{
	ERR_ARG,
	ERR_INP,
	ERR_INF,
	ERR_OUTF,
	ERR_
} t_errcode;

int rep_error(size_t err)
{
	std::string err_msg[] = {
		"give 4 arguments",			   // ARG
		"give non empty string input", // INP
		"unable to open file",		   // INF
		"unable to create output file" // OUTF
	};

	std::cerr << "sed: " << err_msg[err] << std::endl;
	return (err);
}

void replace_line(std::string &line, std::string s1, std::string s2)
{
	size_t pos = line.find(s1, 0);
	const size_t s2_len = s2.length();

	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2_len;
		pos = line.find(s1, pos);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (rep_error(ERR_ARG));

	const std::string if_name = argv[1];
	std::ifstream infile(if_name);
	if (!infile.is_open())
		return (rep_error(ERR_INF));

	const std::string of_name = if_name + ".replace";
	std::ofstream outfile(of_name);
	if (!outfile.is_open())
		return (rep_error(ERR_OUTF));

	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	if (s1.empty())
		return (rep_error(ERR_INP));

	std::string line;
	while (infile)
	{
		std::getline(infile, line);
		if (infile.eof() && line.empty())
			break;
		replace_line(line, s1, s2);
		outfile << line << std::endl;
		line.clear();
	}

	return (0);
}
