#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap	Tom("Tom");
	ClapTrap	Jerry("Jerry");

	std::cout << "This time, " << Tom.getName() << " brought a friend." << std::endl;
	ScavTrap	Coyote("Coyote");
	Tom.setAtkDmg(5);
	std::cout << "But " << Jerry.getName() << " also brought a friend." << std::endl;
	ScavTrap	BipBip("BipBip");
	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy." << std::endl;
	std::cout << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy.\n" << std::endl;

	BipBip.guardGate();
	Coyote.attack(BipBip.getName());
	BipBip.takeDamage(0);
	BipBip.attack(Coyote.getName());
	Coyote.takeDamage(BipBip.getAtkDmg());
	std::cout << "\n" << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy.\n" << std::endl;

	std::cout << Coyote.getName() << " grabbed... an ACME boxing glove" << std::endl;
	Coyote.setAtkDmg(200);
	Coyote.attack(BipBip.getName());
	BipBip.takeDamage(0);
	BipBip.attack("the ACME boxing glove");
	Coyote.takeDamage(500);
	std::cout << "\n" << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy.\n" << std::endl;

	Coyote.attack(BipBip.getName());
	BipBip.beRepaired(10);
	Coyote.beRepaired(10);
	std::cout << BipBip.getName() << " said BIP BIP and ran off into the distance." << std::endl;
	std::cout << Tom.getName() << " facepalmed with this whole situation." << std::endl;
	std::cout << Jerry.getName() << " stole some cheese when nobody was looking." << std::endl;
	std::cout << "\n" << Tom.getName() << " has " << Tom.getAtkDmg() << " power. ";
	std::cout << "Also, " << Tom.getHitPnts() << " health and " << Tom.getEnergyPnts() << " energy." << std::endl;
	std::cout << Jerry.getName() << " has " << Jerry.getAtkDmg() << " power. ";
	std::cout << "Also, " << Jerry.getHitPnts() << " health and " << Jerry.getEnergyPnts() << " energy." << std::endl;
	std::cout << Coyote.getName() << " has " << Coyote.getAtkDmg() << " power. ";
	std::cout << "Also, " << Coyote.getHitPnts() << " health and " << Coyote.getEnergyPnts() << " energy." << std::endl;
	std::cout << BipBip.getName() << " has " << BipBip.getAtkDmg() << " power. ";
	std::cout << "Also, " << BipBip.getHitPnts() << " health and " << BipBip.getEnergyPnts() << " energy.\n" << std::endl;

	ScavTrap	BugsBunny(BipBip);
	ScavTrap	DaffyDuck = Coyote;
	BugsBunny.setName("Bugs Bunny");
	DaffyDuck.setName("Daffy Duck");
	std::cout << "\n" << DaffyDuck.getName() << " has " << DaffyDuck.getAtkDmg() << " power. ";
	std::cout << "Also, " << DaffyDuck.getHitPnts() << " health and " << DaffyDuck.getEnergyPnts() << " energy." << std::endl;
	std::cout << BugsBunny.getName() << " has " << BugsBunny.getAtkDmg() << " power. ";
	std::cout << "Also, " << BugsBunny.getHitPnts() << " health and " << BugsBunny.getEnergyPnts() << " energy.\n" << std::endl;

	return 0;
}
