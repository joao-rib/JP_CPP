#include "Ice.hpp"

AMateria*	Ice::clone(void) const
{
	//std::cout << "Ice was cloned" << std::endl;
	return (new Ice(*this));
}

//CONSTRUCTORS & DESTRUCTORS

Ice::Ice(const Ice &orig): AMateria(orig._type)
{
	//*this = orig;
	//std::cout << "Ice Materia was copied" << std::endl;
}

Ice::Ice(void): AMateria("ice")
{
	//std::cout << "Ice Materia is produced" << std::endl;
}

Ice::~Ice(void)
{
	//std::cout << "Ice Materia destroyed!" << std::endl;
}