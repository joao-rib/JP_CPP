#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Weapon
{
private:
	std::string _Type;
public:
	Weapon() : _Type("") {};
	Weapon(std::string str);
    ~Weapon();
	std::string getType() const;
    void setType(std::string str);
};

#endif
