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
	~Animal();

	void			makeSound(void);
	std::string		getType(void) const;
	void			setType(std::string name);
};

// CONFIRMAR
//
//	virtual ~Animal(void);
//	virtual void	makeSound(void) const;
//
// obs.: When using polymorphism, it is recommended to make the destructor virtual
// so that the destructor of the derived class is called when deleting a base class pointer.

#endif
