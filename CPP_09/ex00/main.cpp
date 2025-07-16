#include "BitcoinExchange.hpp"

static bool check_file(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
try
{
	// Validate arguments and files
	if (argc != 2)
		throw InputException("could not open file.");
	if (!check_file("./data.csv"))
		throw InputException("Could not open data.csv");
	if (!check_file(argv[1]))
		throw InputException("Could not open input file");

	BitcoinExchange().print_values(argv[1]);
}
catch (std::exception &e)
{
	std::cerr << "Error: " << e.what() << std::endl;
}
	return 0;
}

//Input file example
/*
head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648

$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
*/
