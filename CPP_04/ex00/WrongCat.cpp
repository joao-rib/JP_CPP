#include "WrongCat.hpp"

void	WrongCat::makeSound(void) const
{
	std::cout << "A WrongCat made a sound: MEOW!" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "A WrongCat was copy assigned." << std::endl;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &orig): WrongAnimal(orig)
{
	*this = orig;
	std::cout << "A WrongCat was cloned." << std::endl;
}

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	//this->setType("WrongCat");
	std::cout << "A kitty was born." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "A WrongCat just died! Was it the stick?" << std::endl;
}