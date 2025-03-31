#include "FragTrap.hpp"

/*void FragTrap::attack(const std::string &target)
{
	if (this->getHitPnts() == 0)
		std::cout << this->getName() << " can't slap " << target << ", the arms are as dead as the body." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->getName() << " is too tired (or drunk, or hungover, etc). Gotta rest before slapping " << target << "!" << std::endl;
	else
	{
		std::cout << this->getName() << " the FragTrap outright slaps " << target << "!" << std::endl;
		this->setEnergyPnts(this->getEnergyPnts() - 1);
	}
}*/

void FragTrap::highFivesGuy(void)
{
	std::cout << this->getName() << " the FragTrap requests the highest of fives. Up top!" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &orig)
{
	if (this != &orig)
	{
		ClapTrap::operator = (orig);
		this->setHitPnts(100);
		this->setEnergyPnts(100);
		this->setAtkDmg(30);
	}
	std::cout << "Copy assignment of FragTrap " << this->getName() << ", by ACME!" << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap &orig): ClapTrap(orig)
{
	*this = orig;
	std::cout << "FragTrap " << this->getName() << " was copy constructed, like a doppelganger." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setHitPnts(100);
	this->setEnergyPnts(50);
	this->setAtkDmg(20);
	std::cout << "FragTrap " << this->getName() << " suits up for the program!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->getName() << " is too old for this stuff. Lame!" << std::endl;
}

