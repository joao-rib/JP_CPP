#pragma once

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &orig);
	ScavTrap &operator = (const ScavTrap &orig);
	~ScavTrap();

	void			attack(const std::string &target);
	void			guardGate(void);
};

#endif
