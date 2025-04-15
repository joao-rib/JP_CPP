#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << "A Cat made a sound: MEOW!" << std::endl;
}

//GETTERS & SETTERS

std::string Cat::findIdea(int i) const
{
	return (this->_brain->getIdea(i - 1));
}

//CONSTRUCTORS & DESTRUCTORS

Cat &Cat::operator = (const Cat &orig)
{
	if (this != &orig)
	{
		this->setType(orig.getType());
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*orig._brain);
	}
	std::cout << "A Cat was copy assigned." << std::endl;
	return (*this);
}

Cat::Cat(const Cat &orig): Animal(orig)
{
	this->_brain = new Brain(*orig._brain);
	std::cout << "A Cat was cloned." << std::endl;
}

Cat::Cat(void): Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "A kitty was born." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "A Cat just died! Was it the stick?" << std::endl;
	delete this->_brain;
}