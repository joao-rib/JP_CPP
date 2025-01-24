#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new (&horde[i]) Zombie(name);
	return (horde);
}

/*std::string itoa(int n)
{
	size_t	count;
	long	c;

	count = 2;
	c = (long)n;
	if (n < 0)
	{
		c *= -1;
		count++;
	}
	while (c >= 10)
	{
		c /= 10;
		count++;
	}
	char	final_num[count];
	c = (long)n;
	count--;
	final_num[count] = '\0';
	count--;
	if (n < 0)
	{
		c *= -1;
		final_num[0] = '-';
	}
	if (n == 0)
		final_num[0] = '0';
	while (c > 0)
	{
		final_num[count] = (c % 10) + '0';
		c /= 10;
		count--;
	}
	return (std::string(final_num));
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string temp = name + itoa(i + 1);
		horde[i] = Zombie(temp);
	}
	return (horde);
}*/
