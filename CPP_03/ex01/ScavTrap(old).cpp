#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " can't attack " << target << ", they're squished." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->_name << " is too tired. Gotta drink some milk before attacking " << target << "!" << std::endl;
	else
	{
		std::cout << this->_name << " the ScavTrap verbally (only verbally) attacks " << target << "!" << std::endl;
		this->_energy_pnts--;
	}
}

/*void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " is already dead, so whatever." << std::endl;
	else if (this->getHitPnts() > amount)
	{
		std::cout << this->_name << " the ScavTrap takes " << amount << " damage. Dang!" << std::endl;
		this->setHitPnts(this->getHitPnts() - amount);
	}
	else
	{
		std::cout << this->_name << " just took " << amount << " damage and DIED LIKE A DOG!" << std::endl;
		this->setHitPnts(0);
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPnts() == 0)
		std::cout << this->_name << " can't repair itself while dead and scrapped." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->_name << " is too tired. Must recharge before repairing." << std::endl;
	else
	{
		std::cout << this->_name << " the ScavTrap is repaired and gains " << amount << " health. Yay!" << std::endl;
		this->setHitPnts(this->getHitPnts() + amount);
		this->_energy_pnts--;
	}
}*/

void ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is guardGating. They are a ScavTrap, after all." << std::endl;
}

/*std::string ScavTrap::getName(void) const
{
	return (this->_name);
}

void ScavTrap::setName(std::string name)
{
	this->_name = name;
}

unsigned int ScavTrap::getAtkDmg(void) const
{
	return (this->_attack_dmg);
}

void ScavTrap::setAtkDmg(unsigned int value)
{
	this->_attack_dmg = value;
}

unsigned int ScavTrap::getHitPnts(void) const
{
	return (this->_hit_pnts);
}

void ScavTrap::setHitPnts(unsigned int value)
{
	this->_hit_pnts = value;
}

unsigned int ScavTrap::getEnergyPnts(void) const
{
	return (this->_energy_pnts);
}

void ScavTrap::setEnergyPnts(unsigned int value)
{
	this->_energy_pnts = value;
}*/

ScavTrap &ScavTrap::operator = (const ScavTrap &orig)
{
	if (this != &orig)
	{
		this->setName(orig.getName());
		this->setHitPnts(100);
		this->setEnergyPnts(50);
		this->setAtkDmg(20);
	}
	std::cout << "Copy assignment of ScavTrap " << this->getName() << ", by ACME!" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &orig)
{
	*this = orig;
	std::cout << "ScavTrap " << this->getName() << " was copy constructed, cartoonishly." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPnts(100);
	this->setEnergyPnts(50);
	this->setAtkDmg(20);
	std::cout << "ScavTrap " << this->getName() << " was tuned into existence!" << std::endl;
}

/*ScavTrap::ScavTrap(void)
{
	this->_num = 0;
	std::cout << "ScavTrap default constructed!" << std::endl;
}*/

ScavTrap::~ScavTrap(void)
{
	std::cout << this->getName() << " was destroyed. That's all, folks!" << std::endl;
}

