#pragma once

#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice: public AMateria
{
//private:
//	std::string	_type;
public:
	Ice();
	Ice(const Ice &orig);
	virtual ~Ice();

	//std::string const	&getType(void) const;

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif
