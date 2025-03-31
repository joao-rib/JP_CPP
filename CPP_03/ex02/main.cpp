#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap	Tom("Tom");
	ClapTrap	Jerry("Jerry");
	ScavTrap	Coyote("Coyote");
	Tom.setAtkDmg(5);
	ScavTrap	BipBip("BipBip");

	BipBip.guardGate();
	Coyote.attack(BipBip.getName());
	BipBip.takeDamage(0);
	BipBip.attack(Coyote.getName());
	Coyote.takeDamage(BipBip.getAtkDmg());
	std::cout << "\n" << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy.\n" << std::endl;

	FragTrap	Marshall("Marshall");
	FragTrap	Barney("Barney");
	std::cout << "\n" << Marshall.getName() << " has " << Marshall.getAtkDmg() << " power. ";
	std::cout << "Also, " << Marshall.getHitPnts() << " health and " << Marshall.getEnergyPnts() << " energy." << std::endl;
	std::cout << Barney.getName() << " has " << Barney.getAtkDmg() << " power. ";
	std::cout << "Also, " << Barney.getHitPnts() << " health and " << Barney.getEnergyPnts() << " energy.\n" << std::endl;

	Barney.highFivesGuys();
	Marshall.attack("Barney");
	Barney.takeDamage(Marshall.getAtkDmg());

	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy." << std::endl;
	std::cout << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy." << std::endl;
	std::cout << Marshall.getName() << " has " << Marshall.getAtkDmg() << " power. ";
	std::cout << "Also, " << Marshall.getHitPnts() << " health and " << Marshall.getEnergyPnts() << " energy." << std::endl;
	std::cout << Barney.getName() << " has " << Barney.getAtkDmg() << " power. ";
	std::cout << "Also, " << Barney.getHitPnts() << " health and " << Barney.getEnergyPnts() << " energy.\n" << std::endl;

	return 0;
}
