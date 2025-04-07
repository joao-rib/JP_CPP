#include "Dog.hpp"

void	Dog::makeSound(void) const
{
	std::cout << "A Dog made a sound: WOOF WOOF!" << std::endl;
}

Dog &Dog::operator = (const Dog &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "A Dog was copy assigned." << std::endl;
	return (*this);
}

Dog::Dog(const Dog &orig): Animal(orig)
{
	*this = orig;
	std::cout << "A Dog was cloned." << std::endl;
}

Dog::Dog(void): Animal("Dog")
{
	//this->setType("Dog");
	std::cout << "A puppy was born." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "A Dog just died! Like the ending of that movie." << std::endl;
}