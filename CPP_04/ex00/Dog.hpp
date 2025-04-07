#pragma once

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &orig);
	Dog &operator = (const Dog &orig);
	virtual ~Dog();

	void	makeSound(void) const; //override, when using C++11
};

#endif
