#include "Cat.hpp"

void	makeSound(void)
{
	std::cout << "A cat made a sound: MEOW!" << std::endl;
}

Cat &Cat::operator = (const Cat &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "A Cat was copy assigned." << std::endl;
	return (*this);
}

Cat::Cat(const Cat &orig)
{
	*this = orig;
	std::cout << "A Cat was cloned." << std::endl;
}

Cat::Cat(void)
{
	this->setType("Cat");
	std::cout << "A kitty was born." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "A Cat just died! Was it the stick?" << std::endl;
}