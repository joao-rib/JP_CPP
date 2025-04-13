#include "Brain.hpp"

static std::string	itoa(int n)
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
//GETTERS & SETTERS

std::string Brain::getIdea(int i)
{
	if (i >= 0 && i <= 100)
		return (this->_ideas[i]);
	else
		return("no idea");
}

//CONSTRUCTORS & DESTRUCTORS

Brain &Brain::operator = (const Brain &orig)
{
	if (this != &orig)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = "idea number " + itoa(i + 1);
	}
	std::cout << "Brain was copy assigned." << std::endl;
	return (*this);
}

Brain::Brain(const Brain &orig)
{
	*this = orig;
	std::cout << "Brain was cloned." << std::endl;
}

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea number " + itoa(i + 1);
	std::cout << "Brain is brim with bright ideas." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain...dead" << std::endl;
}

