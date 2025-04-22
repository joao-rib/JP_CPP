#include "Cure.hpp"

//MEMBER FUNCTIONS

AMateria*	Cure::clone(void) const
{
	//std::cout << "Cure was cloned" << std::endl;
	return (new Cure(*this));
}

//CONSTRUCTORS & DESTRUCTORS

Cure::Cure(const Cure &orig): AMateria(orig._type)
{
	//*this = orig;
	//std::cout << "Cure Materia was copied" << std::endl;
}

Cure::Cure(void): AMateria("cure")
{
	//std::cout << "Cure Materia is produced" << std::endl;
}

Cure::~Cure(void)
{
	//std::cout << "Cure Materia destroyed!" << std::endl;
}