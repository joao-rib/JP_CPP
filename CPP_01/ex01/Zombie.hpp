#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Zombie
{
private:
	std::string _Name;
public:
	Zombie() : _Name("") {};
	Zombie(std::string name);
    ~Zombie();
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
