#pragma once

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hit_pnts;
	unsigned int _energy_pnts;
	unsigned int _attack_dmg;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &orig);
	ClapTrap &operator = (const ClapTrap &orig);
	~ClapTrap();

	std::string		getName(void) const;
	void			setName(std::string name);
	unsigned int	getHitPnts(void) const;
	void			setHitPnts(unsigned int value);
	unsigned int	getEnergyPnts(void) const;
	void			setEnergyPnts(unsigned int value);
	unsigned int	getAtkDmg(void) const;
	void			setAtkDmg(unsigned int value);

	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
