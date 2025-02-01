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
	//void (MyClass::*funcArray[size])(args) = { &MyClass::func1, &MyClass::func2, etc. }
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
	//(myclass_var.*funcArray[i])(args);
	for (int i = 0; i < 4; i++)
	{
		if (level == message[i])
		{
			(this->*complain_type[i])();
			return ;
		}
	}
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

