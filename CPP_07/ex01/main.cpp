#include "iter.hpp"

void halve(double &num)
{
	num /= 2;
}

void capitalize(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	//return (str);
}

void print_capitals(std::string const &str)
{
	std::cout << '\t' << str << std::endl;
}

int	main(void)
{
	//STRINGS

	std::string array[] = 
	{
		"String1",
		"String2",
		"String3",
	};

	std::cout << "Before iter: " << std::endl;
	std::cout << '\t' << array[0] << std::endl;
	std::cout << '\t' << array[1] << std::endl;
	std::cout << '\t' << array[2] << std::endl;

	::iter(array, 3, capitalize);

	std::cout << "After iter: " << std::endl;
	std::cout << '\t' << array[0] << std::endl;
	std::cout << '\t' << array[1] << std::endl;
	std::cout << '\t' << array[2] << std::endl << std::endl;

	//CONST STRINGS

	const std::string const_array[] = 
	{
		"ConString1",
		"ConString2",
		"ConString3",
	};

	std::cout << "Before iter: " << std::endl;
	std::cout << '\t' << const_array[0] << std::endl;
	std::cout << '\t' << const_array[1] << std::endl;
	std::cout << '\t' << const_array[2] << std::endl;

	std::cout << "This is const iter: " << std::endl;
	::iter(const_array, 3, print_capitals);

	//NUMBERS

	double numbers[] = 
	{
		234,
		13,
		1200.465,
	};

	std::cout << '\n' << "Before iter: " << std::endl;
	std::cout << '\t' << numbers[0] << std::endl;
	std::cout << '\t' << numbers[1] << std::endl;
	std::cout << '\t' << numbers[2] << std::endl;

	::iter(numbers, 3, halve);

	std::cout << "After iter: " << std::endl;
	std::cout << '\t' << numbers[0] << std::endl;
	std::cout << '\t' << numbers[1] << std::endl;
	std::cout << '\t' << numbers[2] << std::endl;

	return (0);
}

