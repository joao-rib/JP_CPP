#pragma once

#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class IMateriaSource
{
//protected:
//	std::string _type;
public:
//	IMateriaSource();
//	IMateriaSource(std::string type);
//	IMateriaSource(const IMateriaSource &orig);
//	IMateriaSource &operator = (const IMateriaSource &orig);
	~IMateriaSource() {};

	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
