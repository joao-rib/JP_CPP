#include "BitcoinExchange.hpp"

static bool check_file(std::string filename)
{
	size_t len = filename.size();

	if (filename == "./data.csv")
		;
	else if (len < 4 || filename.substr(len - 4, 4) != ".txt") //WIP confirmar
		return (false);

	std::ifstream file(filename);
	if (!file.is_open())
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
try
{
	if (argc != 2)
		throw InputException("could not open file");
	if (!check_file("./data.csv"))
		throw InputException("There must be a valid .csv file");
	if (!check_file(argv[1]))
		throw InputException("Argument must be a valid .txt file");

	//BitcoinExchange bitcoin_map = BitcoinExchange();
	//bitcoin_map.store_input(argv[1]);
	BitcoinExchange bitcoin_map = BitcoinExchange(argv[1]); //WIP functions to write
	bitcoin_map.print_values(); //WIP write function
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
