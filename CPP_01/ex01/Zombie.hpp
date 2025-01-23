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
	std::string name;
public:
	Zombie() : name("") {};
	Zombie(std::string name);
    ~Zombie();
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
