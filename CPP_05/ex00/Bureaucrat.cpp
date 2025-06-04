#include "Bureaucrat.hpp"

void	Bureaucrat::makeSound(void) const
{
	std::cout << "An unspecified Bureaucrat made a sound." << std::endl;
}

//GETTERS & SETTERS

std::string const &Bureaucrat::getType(void) const
{
	return (this->_type);
}

void Bureaucrat::setType(std::string type)
{
	this->_type = type;
}

//CONSTRUCTORS & DESTRUCTORS

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &orig)
{
	if (this != &orig)
		this->setType(orig.getType());
	std::cout << "An Bureaucrat was copy assigned." << std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig)
{
	*this = orig;
	std::cout << "An Bureaucrat was cloned." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	//std::cout << this->getType() << " Materia is produced" << std::endl;
}

Bureaucrat::Bureaucrat(void)
{
	this->setType("Typical Bureaucrat");
	std::cout << "An Bureaucrat was born." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "An Bureaucrat just died!" << std::endl;
}

