#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
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
	this->setEnergyPnts(100);
	this->setAtkDmg(30);
	std::cout << "FragTrap " << this->getName() << " suits up for the program!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->getName() << " is too old for this stuff. Lame!" << std::endl;
}

