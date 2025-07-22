#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
try
{
	if (argc < 2)
		throw InputException(": Please insert at sequence of positive numbers");
	PmergeMe pmm = PmergeMe(argv + 1); // WIP Ideal constructor
	// WIP check negatives ("Error" only)
	// WIP check non-numbers
	// WIP check duplicates

	// WIP print unsorted sequence
	pmm.print_unsorted();
	// WIP print sorted sequence
	pmm.print_sorted();
	// WIP Time to process with first container (microseconds, 5 decimals => picoseconds)
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::vectot : ";
	std::cout << std::fixed << std::setprecision(5) << pmm.getTime(TIME_1) << " us" << std::endl;
	// WIP Time to process with second container (microseconds, 5 decimals => picoseconds)
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(5) << pmm.getTime(TIME_2) << " us" << std::endl;
}
catch (std::exception &e)
{
	std::cerr << "Error" << e.what() << std::endl;
}
	return 0;
}

//Output example
/*
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
*/