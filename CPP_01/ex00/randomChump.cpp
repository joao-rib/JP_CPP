#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie chumpZombie = Zombie(name);
    chumpZombie.announce();
}

/*void randomChump(std::string name)
{
    Zombie chumpZombie;
    chumpZombie.setName(name);
    chumpZombie.announce();
}*/
