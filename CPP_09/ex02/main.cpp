#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
try
{
	if (argc < 2)
		throw InputException(": Please insert at sequence of positive numbers");

	PmergeMe pmm = PmergeMe(argv, argc);

	pmm.print_unsorted();
	pmm.print_sorted();

	// Time to process with Vector (microseconds, 5 decimals => picoseconds)
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(pmm.getTime(TIME_1)) << " us" << std::endl;

	// Time to process with Deque (microseconds, 5 decimals => picoseconds)
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(5) << static_cast<double>(pmm.getTime(TIME_2)) << " us" << std::endl;
}
catch (std::exception &e)
{
	std::cerr << "Error" << e.what() << std::endl;
}
	return 0;
}

// TEST: ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

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