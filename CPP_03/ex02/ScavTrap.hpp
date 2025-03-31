#pragma once

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
/*private:
	std::string _name;
	unsigned int _hit_pnts;
	unsigned int _energy_pnts;
	unsigned int _attack_dmg;*/
public:
	//ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &orig);
	ScavTrap &operator = (const ScavTrap &orig);
	~ScavTrap();

/*	std::string		getName(void) const;
	void			setName(std::string name);
	unsigned int	getHitPnts(void) const;
	void			setHitPnts(unsigned int value);
	unsigned int	getEnergyPnts(void) const;
	void			setEnergyPnts(unsigned int value);
	unsigned int	getAtkDmg(void) const;
	void			setAtkDmg(unsigned int value);*/

	void			attack(const std::string &target);
	//void			takeDamage(unsigned int amount);
	//void			beRepaired(unsigned int amount);
	void			guardGate(void);
};

#endif
