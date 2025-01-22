#include "Zombie.hpp"

/*void Zombie::setName(std::string name)
{
	this->name = name;
}*/

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
	std::cout << "Rise from your grave! " << this->name << "!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " rests in peace once again. For now..." << std::endl;
}

