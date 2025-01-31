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
	return (this->_Type);
}

/*void Harl::complain(std::string level)
{
    // Ponteiro para membro da classe para acessar métodos privados
    void (Harl::*ptrToMethod)() = NULL;
    // Harl *ptrToMethod = NULL;
    //int case_level;
    std::string cases[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*array[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};


    for (int i = 0; i < 4; i++)
    {
        if (cases[i] == level)
            
        {
            ptrToMethod = array[i];
            if (ptrToMethod != NULL)
                {
                    std::cout << "[ " << level << " ]" << std::endl;
                    (this->*ptrToMethod)();
                }
        }
    }
    if (!ptrToMethod || level.empty())
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}*/

Harl::Harl(void)
{
	std::cout << "Harl arrives" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has left the building" << std::endl;
}

