#include "BitcoinExchange.hpp"

//WIP build structures

static bool parse_file(std::string filename)
{
	;
}

int	main(int argc, char **argv)
{
try
{
	if (argc != 2)
		throw ; //WIP write exception
	if (!check_data())
		throw ; //WIP write function, see if data.csv exists, and is valid... maybe store values already.
	if (!parse_file(argv[1]))
		throw ; //WIP write function, open file, check formatting
	std::vector bitcoin_vec = store_values(argv[1]); //WIP write function, calculate exchange, save values
	print_values(bitcoin_vec); //WIP write function
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
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
