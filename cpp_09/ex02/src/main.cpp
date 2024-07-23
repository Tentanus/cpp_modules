#include "PmergeMe.hpp"
#include <chrono>
#include <ratio>

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

template <typename Container>
void sort_container(size_t run, int argc, char *argv[])
{
	std::vector<std::chrono::duration<double, std::micro>> result;
	Container numbers = parse_arguments<Container>(argc, argv);

	for (size_t i = 0; i < run; i++)
	{
		std::chrono::time_point<std::chrono::steady_clock> start =
			std::chrono::steady_clock::now();

		Container numbers_copy = numbers;
		PmergeMe pm(numbers_copy);
		pm.sort();

		std::chrono::time_point<std::chrono::steady_clock> end =
			std::chrono::steady_clock::now();

		std::chrono::duration<double, std::micro> diff_us = end - start;
		std::cout << "[" << i + 1 << "] : " << diff_us.count() << " μs"
				  << std::endl;
		result.push_back(diff_us);
	}
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
		sort_container<std::vector<int>>(3, argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
