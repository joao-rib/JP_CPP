#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	ShrubberyCreationForm::beSigned(Bureaucrat &bureau)
{
	if (this->_signature == true)
		std::cout << *this << " is already signed." << std::endl;
	else if (bureau.getGrade() <= this->getSignGrade())
	{
		//this->_signature = true;
		this->setSignature(true);
		std::cout << bureau << " signed " << *this << "." << std::endl;
	}
	else
		throw GradeTooHighException(*this, " cannot be signed by a Bureaucrat of lower grade.");
}

//GETTERS & SETTERS

int const &ShrubberyCreationForm::getSignGrade(void) const
{
	return (this->_grade_sign);
}

int const &ShrubberyCreationForm::getExecGrade(void) const
{
	return (this->_grade_exec);
}

std::string const &ShrubberyCreationForm::getName(void) const
{
	return (this->_name);
}

bool const &ShrubberyCreationForm::getSignature(void) const
{
	return (this->_signature);
}

void ShrubberyCreationForm::setSignature(bool sign)
{
	this->_signature = sign;
}

//CONSTRUCTORS & DESTRUCTORS

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &orig)
{
	if (this != &orig)
		this->_signature = orig.getSignature();
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig): _name(orig._name), _grade_sign(orig._grade_sign), _grade_exec(orig._grade_exec)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->_signature = orig.getSignature();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name, int grade_sign, int grade_exec): _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException(*this, " cannot be higher than 1.");
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException(*this, " cannot be lower than 150.");
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void): _name("Generic"), _grade_sign(150), _grade_exec(150)
{
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const ShrubberyCreationForm& paper)
{
	out << paper.getName() << " ShrubberyCreationForm (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}

// EXCEPTIONS

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(const ShrubberyCreationForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

ShrubberyCreationForm::GradeTooHighException::~GradeTooHighException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException(const ShrubberyCreationForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

ShrubberyCreationForm::GradeTooLowException::~GradeTooLowException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
}