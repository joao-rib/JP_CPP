#pragma once

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &orig);
	FragTrap &operator = (const FragTrap &orig);
	~FragTrap();

	//void			attack(const std::string &target);
	void			highFivesGuys(void);
};

#endif
