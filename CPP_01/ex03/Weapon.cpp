#include "Weapon.hpp"

void Weapon::setType(std::string str)
{
	this->type = str;
}

std::string Weapon::getType() const
{
	return (this->type);
}

Weapon::Weapon(std::string str)
{
	setType(str);
	std::cout << this->type << " forged" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->type << " destroyed" << std::endl;
}

