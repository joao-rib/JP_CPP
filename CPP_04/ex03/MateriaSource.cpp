#include "MateriaSource.hpp"

//MEMBER FUNCTIONS

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!this->_source[i])
		{
			this->_source[i] = m->clone();
			std::cout << m->getType() << " Materia learned." << std::endl;
			return ;
		}
		else if (i == 3)
			std::cout << "This MateriaSource cannot register any more Materias" << std::endl;
		i++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;
	while (i < 4)
	{
		if (this->_source[i] && this->_source[i]->getType() == type)
		{
			std::cout << type << " Materia created." << std::endl;
			return (this->_source[i]->clone());
		}
		else if (i == 3)
			std::cout << "This MateriaSource does not contain that Materia type" << std::endl;
		i++;
	}
	return (NULL);
}

//CONSTRUCTORS & DESTRUCTORS

MateriaSource &MateriaSource::operator = (const MateriaSource &orig)
{
	for (int i = 0; i < 4; i++)
	{
		if (orig._source[i])
			this->_source[i] = orig._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
	//std::cout << "A MateriaSource was copy assigned." << std::endl;
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &orig)
{
	for (int i = 0; i < 4; i++)
	{
		if (orig._source[i])
			this->_source[i] = orig._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
	//std::cout << "A MateriaSource was copied." << std::endl;
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
	//std::cout << "A MateriaSource was compiled" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete (this->_source[i]);
	}
	//std::cout << "This MateriaSource has been erased" << std::endl;
}

