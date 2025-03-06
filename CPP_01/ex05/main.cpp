#include "Harl.hpp"

std::string capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please include an argument" << std::endl;
		return (0);
	}
    Harl harl;
	//harl.complain(argv[1]);
	// OR
	//void (MyClass::*funcPtr)(args) = &MyClass::function;
	//(MyClass.*funcPtr)(arg);
	void (Harl::*complainPtr)(std::string) = &Harl::complain;
	(harl.*complainPtr)(capitalize(argv[1]));
	return (0);
}
