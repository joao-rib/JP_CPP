#pragma once

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &orig);
	DiamondTrap &operator = (const DiamondTrap &orig);
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI(void);
};

#endif
