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

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
	void			setType(std::string name);
};

#endif
