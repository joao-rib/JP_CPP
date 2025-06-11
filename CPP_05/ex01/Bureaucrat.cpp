#include "Bureaucrat.hpp"
#include "Form.hpp"

//MEMBER FUNCTIONS

void	Bureaucrat::signForm(Form &paper)
{
	paper.beSigned(*this);
}

//GETTERS & SETTERS

void Bureaucrat::incGrade(void)
{
	if (--this->_grade < 1)
		throw GradeTooHighException(*this);
}

void Bureaucrat::decGrade(void)
{
	if (++this->_grade > 150)
		throw GradeTooLowException(*this);
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

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &orig)
{
	if (this != &orig)
		_grade = orig.getGrade();
	//std::cout << this << " was copy-referred." << std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig): _name(orig._name), _grade(orig._grade)
{
	//std::cout << this << " was referred." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException(*this);
	if (grade > 150)
		throw GradeTooLowException(*this);
	//std::cout << this << " was hired." << std::endl;
}

Bureaucrat::Bureaucrat(void): _name("Faceless"), _grade(150)
{
	//std::cout << this << " was hired." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << this << " was fired" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (out);
}

// EXCEPTIONS

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat &bureau)
{
	std::ostringstream out;
	out << bureau << " is higher than 1.";
	_msg = out.str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat &bureau)
{
	std::ostringstream out;
	out << bureau << " is lower than 150.";
	_msg = out.str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
}