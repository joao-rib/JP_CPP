#pragma once

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat &orig);
	Cat &operator = (const Cat &orig);
	virtual ~Cat();

	void	makeSound(void) const; //override, when using C++11
};

#endif
