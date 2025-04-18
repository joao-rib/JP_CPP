#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << "A Cat made a sound: MEOW!" << std::endl;
}

//CONSTRUCTORS & DESTRUCTORS

Cat &Cat::operator = (const Cat &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "A Cat was copy assigned." << std::endl;
	return (*this);
}

Cat::Cat(const Cat &orig): Animal(orig)
{
	*this = orig;
	std::cout << "A Cat was cloned." << std::endl;
}

Cat::Cat(void): Animal("Cat")
{
	//this->setType("Cat");
	std::cout << "A kitty was born." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "A Cat just died! Was it the stick?" << std::endl;
}