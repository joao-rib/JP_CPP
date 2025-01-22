#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}

/*Zombie* newZombie(std::string name)
{
	Zombie* heapZombie = new Zombie();
    heapZombie->setName(name);
	return (heapZombie);
}*/
