#include "Animal.hpp"

void	Animal::makeSound(void) const
{
	std::cout << "An unspecified animal made a sound." << std::endl;
}

//GETTERS & SETTERS

std::string Animal::findIdea(int i) const
{
	(void)i;
	return ("no Animal idea");
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

//CONSTRUCTORS & DESTRUCTORS

Animal &Animal::operator = (const Animal &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "An animal was copy assigned." << std::endl;
	return (*this);
}

Animal::Animal(const Animal &orig)
{
	*this = orig;
	std::cout << "An animal was cloned." << std::endl;
}

Animal::Animal(std::string type)
{
	this->setType(type);
	std::cout << "An animal, like a " << this->getType() << ", was born." << std::endl;
}

Animal::Animal(void)
{
	this->setType("Typical Animal");
	std::cout << "An animal was born." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "An animal just died!" << std::endl;
}

