#include "PmergeMe.hpp"

#include <chrono>
#include <list>
#include <ratio>
#include <sys/types.h>
#include <vector>

template <typename Container>
Container parse_arguments(int argc, char *argv[])
{
	Container numbers;
	for (int i = 1; i < argc; i++)
	{
		numbers.push_back(std::stoi(argv[i]));
	}
	return numbers;
}

void print_overview(std::chrono::duration<double, std::micro> time_parse,
					double ms, ssize_t times, std::string container)
{
	std::cout << "Container:\t\t" << container << "\n";
	std::cout << "Succesfull Runs:\t" << times << "\n";
	std::cout << "Duration (μs):\n";
	std::cout << "Parsing :\t\t" << std::to_string(time_parse.count()) << "\n";
	std::cout << "Average :\t\t" << ms * 1000 / times << std::endl;
	std::cout << std::endl;
}

template <typename Container>
size_t estimate_time(double ms, Container numbers)
{
	std::chrono::time_point<std::chrono::steady_clock> time_start =
		std::chrono::steady_clock::now();

	PmergeMe<Container> pm(numbers);
	pm.sort();

	std::chrono::time_point<std::chrono::steady_clock> time_end =
		std::chrono::steady_clock::now();

	return std::chrono::duration_cast<std::chrono::microseconds>(time_end -
																 time_start)
		.count();
}

template <typename Container>
void sort_container(double ms, int argc, char *argv[], std::string container)
{
	std::chrono::time_point<std::chrono::steady_clock> time_start =
		std::chrono::steady_clock::now();
	Container numbers = parse_arguments<Container>(argc, argv);
	std::chrono::time_point<std::chrono::steady_clock> time_parse =
		std::chrono::steady_clock::now();
	std::chrono::duration<double> diff_parse = time_parse - time_start;

	size_t estimate = estimate_time<Container>(ms, numbers);

	size_t times = 0;
	for (; times <= estimate; times++)
	{
		PmergeMe<Container> pm(numbers);
		pm.sort();
	}

	std::chrono::time_point<std::chrono::steady_clock> time_end =
		std::chrono::steady_clock::now();

	result.push_back(diff);
	print_overview(result.at(0), ms, times, container);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << "[number] [number] ..."
				  << std::endl;
		return FAILURE;
	}
	try
	{
		sort_container<std::vector<int>>(10, argc, argv, "vector<int>");
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
