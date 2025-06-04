#include "Bureaucrat.hpp"

//GETTERS & SETTERS

void Bureaucrat::incGrade(void)
{
	this->_grade--;
}

void Bureaucrat::decGrade(void)
{
	this->_grade++;
}

int const &Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

//CONSTRUCTORS & DESTRUCTORS

Bureaucrat::Bureaucrat(const Bureaucrat &orig): _name(orig._name), _grade(orig._grade)
{
	//std::cout << "A Bureaucrat was referred." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	//std::cout << "A Bureaucrat was hired." << std::endl;
}

Bureaucrat::Bureaucrat(void): _name("Faceless"), _grade(150)
{
	//std::cout << "A Bureaucrat was hired." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "The Bureaucrat was fired" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (out);
}

/*Bureaucrat &Bureaucrat::operator ++ (void)
{
	this->_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator ++ (int)
{
	Bureaucrat temp = *this;
	this->_grade++;
	return (temp);
}

Bureaucrat &Bureaucrat::operator -- (void)
{
	this->_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator -- (int)
{
	Bureaucrat temp = *this;
	this->_grade--;
	return (temp);
}*/