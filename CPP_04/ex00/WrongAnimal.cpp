#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound(void) const
{
	std::cout << "An unspecified WrongAnimal made a sound." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "An WrongAnimal was copy assigned." << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &orig)
{
	*this = orig;
	std::cout << "An WrongAnimal was cloned." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->setType(type);
	std::cout << "An WrongAnimal, like a " << this->getType() << ", was born." << std::endl;
}

WrongAnimal::WrongAnimal(void)
{
	this->setType("Typical WrongAnimal");
	std::cout << "An WrongAnimal was born." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "An WrongAnimal just died!" << std::endl;
}

