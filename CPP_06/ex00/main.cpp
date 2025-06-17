#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
try
{
	if (argc != 2)
		throw ScalarConverter::OutsideScopeException("Only one argument permitted.");
	ScalarConverter::converter(argv[1]);
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}