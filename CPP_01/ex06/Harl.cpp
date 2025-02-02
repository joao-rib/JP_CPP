#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[Harl]: I love buildings with cats. What's not to like?" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[Harl]: So, this appartment is surrounded by dogs? You must be joking." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[Harl]: If I don't hear a miau, I will find that very mau." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[Harl]: God help me, I will slap you with my shoe." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*complain_type[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::string message[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	static bool found = false;
	for (int i = 0; i < 4; i++)
	{
		if (level == message[i] || found)
		{
			switch (i)
			{
				case 0:
					(this->*complain_type[0])();
					found = true;
					break;
				case 1:
					(this->*complain_type[1])();
					found = true;
					break;
				case 2:
					(this->*complain_type[2])();
					found = true;
					break;
				case 3:
					(this->*complain_type[3])();
					found = true;
					break;
				default:
					std::cout << "[Harl]: I'm working here! You need anything?" << std::endl;
					return;
			}
		}
	}
	if (!found)
		std::cout << "[Harl]: I'm working here! You need anything?" << std::endl;
    return ;
}

Harl::Harl(void)
{
	std::cout << "Harl arrives" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has left the building" << std::endl;
}

/*#include <iostream>

int main() {
    char grade = 'B';

    switch (grade) {
        case 'A':
            std::cout << "Excellent!\n";
            break;
        case 'B':
        case 'C': // Both cases share the same output
            std::cout << "Good job!\n";
            break;
        case 'D':
            std::cout << "You passed\n";
            break;
        case 'F':
            std::cout << "Better luck next time\n";
            break;
        default:
            std::cout << "Invalid grade\n";
    }

    return 0;
}
*/
