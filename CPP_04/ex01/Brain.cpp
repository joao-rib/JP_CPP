#include "Brain.hpp"

void	Brain::makeSound(void) const
{
	std::cout << "An unspecified Brain made a sound." << std::endl;
}

std::string Brain::getType(void) const
{
	return (this->_type);
}

void Brain::setType(std::string type)
{
	this->_type = type;
}

Brain &Brain::operator = (const Brain &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "An Brain was copy assigned." << std::endl;
	return (*this);
}

Brain::Brain(const Brain &orig)
{
	*this = orig;
	std::cout << "An Brain was cloned." << std::endl;
}

Brain::Brain(std::string type)
{
	this->setType(type);
	std::cout << "An Brain, like a " << this->getType() << ", was born." << std::endl;
}

Brain::Brain(void)
{
	this->setType("Typical Brain");
	std::cout << "An Brain was born." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "An Brain just died!" << std::endl;
}

