#include "Zombie.hpp"

bool validate_number(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "Please include two arguments" << std::endl;;
		return (0);
	}
	if (!validate_number(argv[1]))
	{
		std::cout << "First argument must be a number" << std::endl;;
		return (0);
	}
	int n = atoi(argv[1]);
	if (n == 0)
		return (0);
	Zombie* horde = zombieHorde(n, argv[2]);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	//for (int i = 0; i < n; i++)
	//	delete &horde[i];
	delete[] horde;
	return (0);
}

