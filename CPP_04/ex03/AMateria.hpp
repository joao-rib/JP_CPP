#pragma once

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class ICharacter;

class AMateria
{
protected:
	std::string const _type;
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &orig);
	//AMateria &operator = (const AMateria &orig);
	virtual ~AMateria();

	std::string const	&getType(void) const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif
