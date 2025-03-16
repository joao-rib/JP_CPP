#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap	Tom("Tom");
	ClapTrap	Jerry("Jerry");

	Tom.setAtkDmg(5);
	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	Tom.attack("Jerry");
	Jerry.takeDamage(5);
	Jerry.attack("Tom");
	Tom.takeDamage(0);
	Tom.attack("the air");
	Jerry.takeDamage(0);

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	std::cout << Jerry.getName() << " grabbed... a bazooka?!" << std::endl;
	Jerry.setAtkDmg(50);
	Jerry.attack("Tom");
	Tom.takeDamage(50);
	Tom.attack("Jerry");
	Jerry.attack("Tom");
	Tom.takeDamage(50);

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	std::cout << Jerry.getName() << " starts to grow bored..." << std::endl;
	Jerry.beRepaired(10);
	Tom.beRepaired(10);

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	std::cout << Jerry.getName() << " had an idea! Build a second Tom!" << std::endl;
	ClapTrap Tom2(Tom);
	Tom2.setName("Tom2");
	Tom2.setAtkDmg(5);

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Tom2.getName() << " has " << Tom2.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom2.getHitPnts() << " health and " << Tom2.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	Tom2.attack("Jerry");
	Jerry.takeDamage(5);
	Jerry.attack("Tom");
	Tom2.takeDamage(50);

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Tom2.getName() << " has " << Tom2.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom2.getHitPnts() << " health and " << Tom2.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy.\n" << std::endl;
	std::cout << "It was a fun day for " << Jerry.getName() << std::endl;

	return 0;
}
