#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << ", but I am also " << ClapTrap::getName() << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &orig)
{
	if (this != &orig)
	{
		ClapTrap::operator = (orig);
		_name = orig._name;
		FragTrap::initHitPnts();
		ScavTrap::initEnergyPnts();
		FragTrap::initAtkDmg();
	}
	std::cout << "Copy assignment of DiamondTrap " << _name << " by an evil corporation, like Amazon!" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig): ClapTrap(orig), ScavTrap(orig), FragTrap(orig)
{
	*this = orig;
	std::cout << "DiamondTrap " << _name << " was copy constructed by SkyNet, actually." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	FragTrap::initHitPnts();
	ScavTrap::initEnergyPnts();
	FragTrap::initAtkDmg();
//	_hit_pnts = FragTrap::_hit_pnts;
//	_energy_pnts = ScavTrap::_energy_pnts;
//	_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap " << _name << " has been built, faster, stronger, probably!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Even a DiamondTrap like " << _name << " breaks down..." << std::endl;
}

