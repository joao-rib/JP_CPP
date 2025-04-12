#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &orig);
	Animal &operator = (const Animal &orig);
	virtual ~Animal();

	std::string		getType(void) const;
	void			setType(std::string name);

	virtual void	makeSound(void) const;
};

#endif
