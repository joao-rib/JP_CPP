#include "RPN.hpp"

int	main(int argc, char **argv)
{
try
{
	if (argc != 2)
		throw InputException("");

	RPN(argv[1]).print_result();
}
catch (std::exception &e)
{
	std::cerr << "Error" << e.what() << std::endl;
}
	return 0;
}

//Example
/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
*/
