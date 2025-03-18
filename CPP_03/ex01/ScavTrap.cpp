#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPnts() == 0)
		std::cout << this->getName() << " can't attack " << target << ", they're kaput." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->getName() << " is too tired. Gotta drink some milk before attacking " << target << "!" << std::endl;
	else
	{
		std::cout << this->getName() << " the ScavTrap hilariously attacks " << target << "!" << std::endl;
		this->setEnergyPnts(this->getEnergyPnts() - 1);
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " is guardGating. They are a ScavTrap, after all." << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &orig)
{
	if (this != &orig)
	{
		ClapTrap::operator = (orig);
		//this->setName(orig.getName());
		this->setHitPnts(100);
		this->setEnergyPnts(50);
		this->setAtkDmg(20);
	}
	std::cout << "Copy assignment of ScavTrap " << this->getName() << ", by ACME!" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &orig): ClapTrap(orig)
{
	//*this = orig;
	std::cout << "ScavTrap " << this->getName() << " was copy constructed, cartoonishly." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	//this->setName(name);
	this->setHitPnts(100);
	this->setEnergyPnts(50);
	this->setAtkDmg(20);
	std::cout << "ScavTrap " << this->getName() << " was tuned into existence!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->getName() << " was destroyed. That's all, folks!" << std::endl;
}

