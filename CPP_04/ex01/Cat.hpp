#pragma once

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain	*_brain;
public:
	Cat();
	Cat(const Cat &orig);
	Cat &operator = (const Cat &orig);
	virtual ~Cat();

	std::string	findIdea(int i);

	void	makeSound(void) const;
};

#endif
