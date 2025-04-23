#include "Ice.hpp"
#include "ICharacter.hpp"

//MEMBER FUNCTIONS

void	Ice::use(ICharacter &target)
{
	std::cout << "Ice spell freezes " << target.getName() << " to the bone" << std::endl;
}

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