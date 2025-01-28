#pragma once

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class HumanB
{
private:
	std::string _Name;
    Weapon *_Weap;
public:
	HumanB() : _Name("") {};
	HumanB(std::string str);
    ~HumanB();
	void attack();
    void setWeapon(Weapon &weap);
};

#endif
