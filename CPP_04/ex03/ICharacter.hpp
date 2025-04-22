#pragma once

#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class AMateria;

class ICharacter
{
//protected:
//	std::string const _name;
public:
//	ICharacter();
//	ICharacter(const ICharacter &orig);
//	ICharacter &operator = (const ICharacter &orig);
	virtual ~ICharacter() {}; //WIP esclarecer

	virtual std::string	const	&getName(void) const = 0;

	virtual void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter &target) = 0;
};

#endif
