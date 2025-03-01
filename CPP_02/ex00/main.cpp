#include "Zombie.hpp"

int	main(int argc, char** argv)
{
	if (argc != 3)
    {
        std::cout << "Please include two arguments" << std::endl;;
		return (0);
    }
	Zombie* patientZero = newZombie(argv[1]);
	patientZero->announce();
    randomChump(argv[2]);
    delete patientZero;
	return (0);
}

/*int	main(int argc, char** argv)
{
	if (argc != 3)
		return (0);
	Zombie stackZombie;
	Zombie* heapZombie = stackZombie.newZombie(argv[1]);
	heapZombie->announce();
    delete heapZombie;
	return (0);
}*/

