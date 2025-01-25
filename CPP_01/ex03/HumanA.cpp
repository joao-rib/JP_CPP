#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->arma.getType() << std::endl;
}

HumanA::HumanA(std::string str, Weapon &weap) : name(str), arma(weap)
{
    //this->name = str;
	//this->arma = weap;

	std::cout << this->name << " (A) born" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->name << " (A) died" << std::endl;
}

