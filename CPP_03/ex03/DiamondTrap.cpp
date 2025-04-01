#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << ", but I am also " << ClapTrap::getName() << std::endl;
}

/*DiamondTrap &DiamondTrap::operator = (const DiamondTrap &orig)
{
	if (this != &orig)
	{
		ClapTrap::operator = (orig);
		_name = orig.getName() + "_clap_name";
		ClapTrap::setHitPnts(FragTrap::getHitPnts());
		ClapTrap::setEnergyPnts(ScavTrap::getEnergyPnts());
		ClapTrap::setAtkDmg(FragTrap::getAtkDmg());
		_hit_pnts = FragTrap::_hit_pnts;
		_energy_pnts = ScavTrap::_energy_pnts;
		_attack_dmg = FragTrap::_attack_dmg;
		this->setHitPnts(100);
		this->setEnergyPnts(50);
		this->setAtkDmg(30);
	}
	std::cout << "Copy assignment of DiamondTrap " << _name << " by an evil corporation, like Amazon!" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig): ClapTrap(orig), FragTrap(orig), ScavTrap(orig)
{
	*this = orig;
	std::cout << "DiamondTrap " << _name << " was copy constructed by SkyNet, actually." << std::endl;
}*/

void	DiamondTrap::baseStats(void)
{
	ClapTrap::_name = _name + "_clap_name";
	_hit_pnts = FragTrap::_hit_pnts;
	_energy_pnts = ScavTrap::_energy_pnts;
	_attack_dmg = FragTrap::_attack_dmg;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	//_name = name + "_clap_name";
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	baseStats();
	/*ClapTrap::setHitPnts(FragTrap::getHitPnts());
	ClapTrap::setEnergyPnts(ScavTrap::getEnergyPnts());
	ClapTrap::setAtkDmg(FragTrap::getAtkDmg());*/
	/*_hit_pnts = FragTrap::_hit_pnts;
	_energy_pnts = ScavTrap::_energy_pnts;
	_attack_dmg = FragTrap::_attack_dmg;*/
	/*this->setHitPnts(100);
	this->setEnergyPnts(50);
	this->setAtkDmg(30);*/
	std::cout << "DiamondTrap " << _name << " has been built, faster, stronger, probably!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Even a DiamondTrap like " << _name << " breaks down..." << std::endl;
}

