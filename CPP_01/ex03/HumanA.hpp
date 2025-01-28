#pragma once

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class HumanA
{
private:
	std::string _Name;
	Weapon &_Weap;
public:
	//HumanA() : name("") {};
	HumanA(std::string str, Weapon &weap);
	~HumanA();
	void attack();
};

#endif

