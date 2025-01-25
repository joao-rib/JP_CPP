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
	std::string type; //MUDAR NOMES DE VARS PRIVADAS
public:
	Weapon() : type("") {};
	Weapon(std::string str);
    ~Weapon();
	std::string getType() const;
    void setType(std::string str);
};

#endif

/*#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"


class Weapon
{
    
private:

    std::string _type;
    
public:

    // constructor with args
    Weapon(std::string name);

    // destructor
    ~Weapon();

    // Methods
    std::string getType() const;
    void        setType(std::string new_type);

};

#endif*/
