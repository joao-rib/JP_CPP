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
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;
public:
	Contact() {};
	void create_contact(void);
	void write_value(std::string& variable, const std::string& field);
	bool validate_number(std::string str);
	std::string get_info(const std::string& field);
};

#endif


/*#ifndef ZOMBIE_H
#define ZOMBIE_H
# include <iostream>


class Zombie
{
private:
    std::string _Name;

public:

    // Construcot
    Zombie();
    
    // Constructor with atributes
    Zombie(std::string NAME);

    // Destructor
    ~Zombie();

    // Methods

    // zumbie announces itself
    void    announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif*/
