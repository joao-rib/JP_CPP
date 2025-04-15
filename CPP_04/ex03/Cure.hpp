#pragma once

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure: public AMateria
{
//private:
//	std::string	_type;
public:
	Cure();
	Cure(const Cure &orig);
	virtual ~Cure();

	//std::string const	&getType(void) const;

	virtual AMateria	*clone() const;
	//virtual void		use(ICharacter &target);
};

#endif
