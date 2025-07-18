#include "RPN.hpp"

static bool	isDelim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	else
		return (false);
}

static std::string	trim_whitespace(const std::string& str)
{
	int i = 0;
	while (isDelim(str[i]))
		i++;
	if (!str[i])
		return ("");

	size_t j = str.size() - 1;
	while (isDelim(str[j]))
		j--;
	return (str.substr(i, j - i + 1));
}

static bool	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static bool	isOpToken(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

static bool parse_arg(std::string av)
{
	av = trim_whitespace(av);
	size_t len = av.size();
	if (len < 5 || !(len % 2) || !isDigit(av[0]) || !isOpToken(av[len - 1]))
		return (false);
	int j = 1;
	for (unsigned int i = 0; i < av.size(); i++, j *= -1) // Numbers or operators in even; whitespace in odd
	{ 
		if ((j > 0 && !(isDigit(av[i]) || isOpToken(av[i])))
			|| (j < 0 && !isDelim(av[i])))
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
try
{
	// Validate arguments
	if (argc != 2 || !parse_arg(argv[1]))
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
