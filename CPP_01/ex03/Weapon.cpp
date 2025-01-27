#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
	if (this->_Type[0])
		std::cout << this->_Type << " became a " << str << std::endl;
	this->_Type = str;
}

std::string Weapon::getType() const
{
	return (this->_Type);
}

Weapon::Weapon(std::string str)
{
	setType(str);
	std::cout << this->_Type << " forged" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->_Type << " destroyed" << std::endl;
}

