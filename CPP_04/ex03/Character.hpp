#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

#include "ICharacter.hpp"

class Character: public ICharacter
{
protected:
	std::string const	_name;
	AMateria			*_slot[4];
public:
	Character(std::string const name);
	Character(const Character &orig);
	//Character &operator = (const Character &orig);
	virtual ~Character();

	virtual std::string	const	&getName(void) const;

	virtual void	equip(AMateria *m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter &target);
};

#endif
