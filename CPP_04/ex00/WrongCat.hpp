#pragma once

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &orig);
	WrongCat &operator = (const WrongCat &orig);
	virtual ~WrongCat();

	void	makeSound(void) const; //override, when using C++11
};

#endif
