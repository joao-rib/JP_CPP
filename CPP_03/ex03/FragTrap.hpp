#pragma once

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &orig);
	FragTrap &operator = (const FragTrap &orig);
	~FragTrap();

	void			highFivesGuys(void);
};

#endif
