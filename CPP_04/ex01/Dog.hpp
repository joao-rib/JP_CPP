#pragma once

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog &orig);
	Dog &operator = (const Dog &orig);
	virtual ~Dog();

	std::string	findIdea(int i) const;

	void	makeSound(void) const;
};

#endif
