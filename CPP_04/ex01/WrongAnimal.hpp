#pragma once

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &orig);
	WrongAnimal &operator = (const WrongAnimal &orig);
	~WrongAnimal();

	std::string		getType(void) const;
	void			setType(std::string name);

	void			makeSound(void) const;
};

#endif
