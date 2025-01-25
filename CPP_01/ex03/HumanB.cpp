#include "HumanB.hpp"

void HumanB::setWeapon(Weapon weap)
{
	this->arma = weap;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->arma.getType() << std::endl;
}

HumanB::HumanB(std::string str)
{
    this->name = str;
	std::cout << this->name << " (B) born" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " (B) died" << std::endl;
}

