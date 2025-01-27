#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weap)
{
	std::cout << this->_Name << " sees a " << weap.getType() << std::endl;
	this->_Weap = &weap;
	std::cout << this->_Name << " gladly grabbed a " << this->_Weap->getType() << std::endl;
}

void HumanB::attack(void)
{
	if (this->_Weap && !this->_Weap->getType().empty())
		std::cout << this->_Name << " attacks with a " << this->_Weap->getType() << std::endl;
	else
		std::cout << this->_Name << " attacks... bare-handed? Oh dear" << std::endl;
}

HumanB::HumanB(std::string str)
{
    this->_Name = str;
	this->_Weap = NULL;
	std::cout << this->_Name << " (B) born without a weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_Name << " (B) died" << std::endl;
}

