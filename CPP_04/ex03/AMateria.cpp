#include "AMateria.hpp"
#include "ICharacter.hpp"

//MEMBER FUNCTIONS

void	AMateria::use(ICharacter &target)
{
	std::cout << this->getType() << " was used on " << target.getName() << std::endl;
}

//GETTERS & SETTERS

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

//CONSTRUCTORS & DESTRUCTORS

/*AMateria &AMateria::operator = (const AMateria &orig)
{
	if (this != &orig)
		_type = orig.getType();
	//std::cout << this->getType() << " Materia was copy assigned" << std::endl;
	return (*this);
}*/

AMateria::AMateria(const AMateria &orig): _type(orig._type)
{
	//*this = orig;
	//std::cout << this->getType() << " Materia was copied" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	//_type = type;
	//std::cout << this->getType() << " Materia is produced" << std::endl;
}

AMateria::~AMateria(void)
{
	//std::cout << this->getType() << " Materia destroyed!" << std::endl;
}

