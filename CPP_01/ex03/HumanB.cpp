#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weap)
{
	this->_Weap = &weap;
}

void HumanB::attack(void)
{
	std::cout << this->_Name << " attacks with a " << this->_Weap->getType() << std::endl;
}

HumanB::HumanB(std::string str)
{
    this->_Name = str;
	std::cout << this->_Name << " (B) born" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_Name << " (B) died" << std::endl;
}

