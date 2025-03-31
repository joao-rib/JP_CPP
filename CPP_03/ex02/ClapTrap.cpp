#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " can't attack " << target << " on account of currently being dead!" << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->_name << " is too tired. Must recharge before attacking " << target << "!" << std::endl;
	else
	{
		std::cout << this->_name << " the ClapTrap attacks " << target << "!" << std::endl;
		this->_energy_pnts--;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " is already dead, so whatever." << std::endl;
	else if (this->getHitPnts() > amount)
	{
		std::cout << this->_name << " the ClapTrap takes " << amount << " damage. Dang!" << std::endl;
		this->setHitPnts(this->getHitPnts() - amount);
	}
	else
	{
		std::cout << this->_name << " just took " << amount << " damage and DIED LIKE A DOG!" << std::endl;
		this->setHitPnts(0);
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " can't repair itself while dead and scrapped." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->_name << " is too tired. Must recharge before repairing." << std::endl;
	else
	{
		std::cout << this->_name << " the ClapTrap is repaired and gains " << amount << " health. Yay!" << std::endl;
		this->setHitPnts(this->getHitPnts() + amount);
		this->_energy_pnts--;
	}
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

unsigned int ClapTrap::getAtkDmg(void) const
{
	return (this->_attack_dmg);
}

void ClapTrap::setAtkDmg(unsigned int value)
{
	this->_attack_dmg = value;
}

unsigned int ClapTrap::getHitPnts(void) const
{
	return (this->_hit_pnts);
}

void ClapTrap::setHitPnts(unsigned int value)
{
	this->_hit_pnts = value;
}

unsigned int ClapTrap::getEnergyPnts(void) const
{
	return (this->_energy_pnts);
}

void ClapTrap::setEnergyPnts(unsigned int value)
{
	this->_energy_pnts = value;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &orig)
{
	if (this != &orig)
	{
		this->setName(orig.getName());
		this->setHitPnts(10);
		this->setEnergyPnts(10);
		this->setAtkDmg(0);
	}
	std::cout << "Copy assignment of ClapTrap " << this->getName() << " in factory assembly!" << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
	*this = orig;
	std::cout << "ClapTrap " << this->getName() << " was copy constructed, as machines do!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->setName(name);
	this->setHitPnts(10);
	this->setEnergyPnts(10);
	this->setAtkDmg(0);
	std::cout << "ClapTrap " << this->getName() << " was built, meatbag!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->getName() << " broke doooownnn..." << std::endl;
}

