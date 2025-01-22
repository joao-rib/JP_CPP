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
	Zombie(std::string name);
    ~Zombie();
	void announce(void);
	//void setName(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

/*class Zombie
{
private:
	std::string name;
public:
	Zombie();
    ~Zombie();
	void announce(void);
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);
};*/

#endif
