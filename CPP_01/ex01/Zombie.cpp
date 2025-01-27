#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_Name = name;
	std::cout << "Rise from your grave! " << this->_Name << "!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_Name << " rests in peace once again. For now..." << std::endl;
}

