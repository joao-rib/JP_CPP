#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please include two arguments" << std::endl;
        return (0);
	}
    Harl harl;
	harl.complain(argv[1]);
	return (0);
}
