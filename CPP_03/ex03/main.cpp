#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap	Arnie("Arnoldo");
	DiamondTrap	Enemy("Teh-Mil");

	Arnie.whoAmI();
	Enemy.whoAmI();

	std::cout << "\n" << Arnie.getName() << " has " << Arnie.getAtkDmg() << " power. ";
	std::cout << "Also, " << Arnie.getHitPnts() << " health and " << Arnie.getEnergyPnts() << " energy." << std::endl;
	std::cout << Enemy.getName() << " has " << Enemy.getAtkDmg() << " power. ";
	std::cout << "Also, " << Enemy.getHitPnts() << " health and " << Enemy.getEnergyPnts() << " energy.\n" << std::endl;

	Arnie.attack("Teh-Mil");
	Enemy.takeDamage(Arnie.getAtkDmg());
	Enemy.beRepaired(100);
	Enemy.attack("Arnoldo");
	Arnie.takeDamage(Enemy.getAtkDmg());
	Enemy.highFivesGuys();
	Arnie.guardGate();

	std::cout << "\n" << Arnie.getName() << " has " << Arnie.getAtkDmg() << " power. ";
	std::cout << "Also, " << Arnie.getHitPnts() << " health and " << Arnie.getEnergyPnts() << " energy." << std::endl;
	std::cout << Enemy.getName() << " has " << Enemy.getAtkDmg() << " power. ";
	std::cout << "Also, " << Enemy.getHitPnts() << " health and " << Enemy.getEnergyPnts() << " energy.\n" << std::endl;

	/*DiamondTrap	Arnie2(Arnie);
	DiamondTrap	Enemy2 = Enemy;
	Arnie2.setName("Ex-Terminator");
	Enemy2.setName("Teh-Doeish-Mil");

	Arnie2.whoAmI();
	Enemy2.whoAmI();
	std::cout << "\n" << Arnie2.getName() << " has " << Arnie2.getAtkDmg() << " power. ";
	std::cout << "Also, " << Arnie2.getHitPnts() << " health and " << Arnie2.getEnergyPnts() << " energy." << std::endl;
	std::cout << Enemy2.getName() << " has " << Enemy2.getAtkDmg() << " power. ";
	std::cout << "Also, " << Enemy2.getHitPnts() << " health and " << Enemy2.getEnergyPnts() << " energy.\n" << std::endl;*/

	return 0;
}
