#include "PmergeMe.hpp"

#include <cstddef>
#include <ratio>
#include <sys/types.h>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

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
					std::chrono::duration<double, std::milli> time_end,
					ssize_t runs, std::string container)
{
	std::cout << "\nContainer:\t\t" << container << "\n";
	std::cout << "Duration (μs):\n";
	std::cout << "\tParsing :\t" << time_parse.count() << " μs\n\n";
	std::cout << "\tDuration:\t" << time_end.count() << " ms\n";
	std::cout << "\tRuns:\t\t" << runs << "\n";
	std::cout << "\tAverage :\t" << time_end.count() * 1000 / runs << std::endl;
	std::cout << std::endl;
}

template <typename Container>
double estimate_time(double ms, Container numbers)
{
	const size_t n = 5;
	std::chrono::time_point<std::chrono::steady_clock> time_start =
		std::chrono::steady_clock::now();

	for (size_t i = 0; i < n; i++)
	{
		PmergeMe<Container> pm(numbers);
		pm.sort();
	}

	std::chrono::time_point<std::chrono::steady_clock> time_end =
		std::chrono::steady_clock::now();
	std::chrono::duration<double, std::micro> diff = time_end - time_start;
	double ms_in_micro = ms * 1000;
	double micro_per_run = diff.count() / n;
	double ret = ms_in_micro / micro_per_run;

	std::cout << "Estimate:" << "\n";
	std::cout << "\ttime for " << n << " runs:\t" << diff.count() << " μs\n";
	std::cout << "\tms in μs\t\t" << ms_in_micro << " μs\n";
	std::cout << "\tmicro/run\t\t" << micro_per_run << " μs/run\n";
	std::cout << "\tEstimate runs:\t\t" << ret << " runs\n" << std::endl;
	return ret;
}

template <typename Container>
void sort_container(double ms, int argc, char *argv[], std::string container)
{
	std::chrono::time_point<std::chrono::steady_clock> time_start =
		std::chrono::steady_clock::now();
	Container numbers = parse_arguments<Container>(argc, argv);
	std::chrono::time_point<std::chrono::steady_clock> time_parse =
		std::chrono::steady_clock::now();
	std::chrono::duration<double, std::micro> diff_parse =
		time_parse - time_start;

	size_t estimate = estimate_time<Container>(ms, numbers);
	// (void)ms;
	// size_t estimate = 10; // TODO: remove

	std::chrono::time_point<std::chrono::steady_clock> time_estimate =
		std::chrono::steady_clock::now();

	size_t times = 0;
	for (; times <= estimate; times++)
	{
		Container copy(numbers);
		PmergeMe<Container> pm(copy);
		pm.sort();
		std::cout << "sorted PmergeMe [" << container << "]: " << std::is_sorted(copy.begin(), copy.end()) << std::endl;
	}

	std::chrono::time_point<std::chrono::steady_clock> time_end =
		std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff_end =
		time_end - time_estimate;

	print_overview(diff_parse, diff_end, times, container);
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
		sort_container<std::vector<int>>(10000, argc, argv, "vector<int>");
		sort_container<std::list<int>>(10000, argc, argv, "list<int>");
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
