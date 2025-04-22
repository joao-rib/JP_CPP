#pragma once

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
protected:
	AMateria *_source[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &orig);
	MateriaSource &operator = (const MateriaSource &orig);
	~MateriaSource();

	virtual void		learnMateria(AMateria *m);
	virtual AMateria	*createMateria(std::string const &type);
};

#endif
