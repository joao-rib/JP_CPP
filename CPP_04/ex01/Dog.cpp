#include "Dog.hpp"

void	Dog::makeSound(void) const
{
	std::cout << "A Dog made a sound: WOOF WOOF!" << std::endl;
}

//GETTERS & SETTERS

std::string Dog::findIdea(int i)
{
	return (this->_brain->getIdea(i - 1));
}

//CONSTRUCTORS & DESTRUCTORS

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
	this->_brain = new Brain();
	std::cout << "A puppy was born." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "A Dog just died! Like the ending of that movie." << std::endl;
	delete this->_brain;
}