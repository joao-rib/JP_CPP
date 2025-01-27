#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->_Name << " attacks with a " << this->_Weap.getType() << std::endl;
}

HumanA::HumanA(std::string str, Weapon &weap) : _Name(str), _Weap(weap)
{
    //this->name = str;
	//this->arma = weap;

	std::cout << this->_Name << " (A) born" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_Name << " (A) died" << std::endl;
}

