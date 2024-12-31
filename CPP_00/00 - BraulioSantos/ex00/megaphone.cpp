#include <iostream>

std::string capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return str;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; av[i]; i++)
			std::cout << capitalize(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
