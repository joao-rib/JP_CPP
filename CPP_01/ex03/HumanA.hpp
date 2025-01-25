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
	std::string name;
	Weapon &arma; //MUDAR NOMES DE VARS PRIVADAS
public:
	//HumanA() : name("") {};
	HumanA(std::string str, Weapon &weap);
	~HumanA();
	void attack();
};

#endif

/*#ifndef HUMAN_A_H
#define HUMAN_A_H


class Weapon;

class HumanA
{


private:
    std::string _Name;
    Weapon &_Weapon;

public:

    // // default constructor
    // HumanA();

    // constructor with args
    HumanA(std::string name_set, Weapon &weapon_set);

    // destructor
    ~HumanA();
    
    void    attack();

};

#endif*/
