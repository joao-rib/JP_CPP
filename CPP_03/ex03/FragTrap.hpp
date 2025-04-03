#pragma once

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
protected:
	void 	initHitPnts(void);
	void 	initEnergyPnts(void);
	void 	initAtkDmg(void);
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &orig);
	FragTrap &operator = (const FragTrap &orig);
	~FragTrap();

	void			highFivesGuys(void);
};

#endif
