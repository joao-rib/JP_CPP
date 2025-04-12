#pragma once

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Brain
{
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &orig);
	Brain &operator = (const Brain &orig);
	virtual ~Brain();

	std::string	getIdea(int i);
};

#endif
