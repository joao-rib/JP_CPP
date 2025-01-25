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
	std::string name;
    Weapon *arma;
public:
	HumanB() : name("") {};
	HumanB(std::string str);
    ~HumanB();
	void attack();
    void setWeapon(Weapon &weap);
};

#endif

/*#ifndef HUMAN_B_H
#define HUMAN_B_H

class Weapon;

class HumanB
{

private:

    std::string _Name;
    Weapon *_Weapon;

public:

    // constructor with args
    HumanB(std::string name_set);

    // destructor
    ~HumanB();

    void    setWeapon(Weapon &add_weapon);
    void    attack();

};

#endif*/
