#include "DiamondTrap.hpp"

/*void DiamondTrap::attack(const std::string &target)
{
	if (this->getHitPnts() == 0)
		std::cout << this->getName() << " can't slap " << target << ", the arms are as dead as the body." << std::endl;
	else if (this->getEnergyPnts() == 0)
		std::cout << this->getName() << " is too tired (or drunk, or hungover, etc). Gotta rest before slapping " << target << "!" << std::endl;
	else
	{
		std::cout << this->getName() << " the DiamondTrap outright slaps " << target << "!" << std::endl;
		this->setEnergyPnts(this->getEnergyPnts() - 1);
	}
}*/

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << ", but I am also " << ClapTrap::getName() << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &orig)
{
	if (this != &orig)
	{
		ClapTrap::operator = (orig);
		_name = orig.getName() + "_clap_name";
		/*ClapTrap::setHitPnts(FragTrap::getHitPnts());
		ClapTrap::setEnergyPnts(ScavTrap::getEnergyPnts());
		ClapTrap::setAtkDmg(FragTrap::getAtkDmg());*/
		_hit_pnts = FragTrap::_hit_pnts;
		_energy_pnts = ScavTrap::_energy_pnts;
		_attack_dmg = FragTrap::_attack_dmg;
		/*this->setHitPnts(100);
		this->setEnergyPnts(50);
		this->setAtkDmg(30);*/
	}
	std::cout << "Copy assignment of DiamondTrap " << _name << " by an evil corporation, like Amazon!" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig): ClapTrap(orig), FragTrap(orig), ScavTrap(orig)
{
	*this = orig;
	std::cout << "DiamondTrap " << _name << " was copy constructed by SkyNet, actually." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	_name = name + "_clap_name";
	std::cout << FragTrap::getHitPnts() << " hit points." << std::endl;
	std::cout << FragTrap::_hit_pnts << " hit points." << std::endl;
	std::cout << ScavTrap::getEnergyPnts() << " energy points." << std::endl;
	std::cout << ScavTrap::_energy_pnts << " energy points." << std::endl;
	std::cout << FragTrap::getAtkDmg() << " attack damage." << std::endl;
	std::cout << FragTrap::_attack_dmg << " attack damage." << std::endl;
	/*ClapTrap::setHitPnts(FragTrap::getHitPnts());
	ClapTrap::setEnergyPnts(ScavTrap::getEnergyPnts());
	ClapTrap::setAtkDmg(FragTrap::getAtkDmg());*/
	_hit_pnts = FragTrap::_hit_pnts;
	_energy_pnts = ScavTrap::_energy_pnts;
	_attack_dmg = FragTrap::_attack_dmg;
	/*this->setHitPnts(100);
	this->setEnergyPnts(50);
	this->setAtkDmg(30);*/
	std::cout << "DiamondTrap " << _name << " has been built, faster, stronger, probably!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Even a DiamondTrap like " << _name << " breaks down..." << std::endl;
}

