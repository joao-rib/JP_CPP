#include "Character.hpp"
#include "AMateria.hpp"

//MEMBER FUNCTIONS

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "No Materia for " << this->getName() << " to equip" << std::endl;
		return ;
	}
	int	i = 0;
	while (i < 4)
	{
		if (!this->_slot[i])
		{
			this->_slot[i] = m;
			std::cout << this->getName() << " equipped " << m->getType() << " to inventory slot " << i << std::endl;
			return ;
		}
		else if (i == 3)
			std::cout << this->getName() << "'s inventory is full" << std::endl;
		i++;
	}
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Inventory slot " << idx << " does not exist" << std::endl;
		return ;
	}
	if (!this->_slot[idx])
	{
		std::cout << "Inventory slot " << idx << " does not contain any Materia" << std::endl;
		return ;
	}
	this->_slot[idx] = NULL;
	std::cout << this->getName() << " unequipped " << this->_slot[idx]->getType() << " from inventory slot " << idx << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Inventory slot " << idx << " does not exist" << std::endl;
		return ;
	}
	if (!this->_slot[idx])
	{
		std::cout << "Inventory slot " << idx << " does not contain any Materia" << std::endl;
		return ;
	}
	std::cout << this->getName() << " used " << this->_slot[idx]->getType() << " on " << target.getName() << std::endl;
	this->_slot[idx]->use(target);
}

//GETTERS & SETTERS

std::string const &Character::getName(void) const
{
	return (this->_name);
}

//CONSTRUCTORS & DESTRUCTORS

/*Character &Character::operator = (const Character &orig)
{
	if (this != &orig)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = "idea number " + itoa(i + 1);
	}
	//std::cout << "Character was copy assigned." << std::endl;
	return (*this);
}*/

Character::Character(const Character &orig): _name(orig._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (orig._slot[i])
			this->_slot[i] = orig._slot[i]->clone();
		else
			this->_slot[i] = NULL;
	}
	//std::cout << "Character was cloned." << std::endl;
}

Character::Character(std::string const name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	//std::cout << this->getName() << " joined the party!" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete (this->_slot[i]);
	}
	//std::cout << this->getName() << " reached the end of the game" << std::endl;
}

