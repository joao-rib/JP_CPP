#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature() == false)
		std::cout << *this << " is not signed." << std::endl; //WIP throw
	else if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooHighException(*this, " cannot be executed by a Bureaucrat of lower grade."); //WIP corrigir mensagem de erro
	}
	// WIP Create <target>_shrubbery in the working directory and writes ASCII trees inside it
}

//GETTERS & SETTERS

/*int const &ShrubberyCreationForm::getSignGrade(void) const
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
}*/

//CONSTRUCTORS & DESTRUCTORS

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &orig)
{
	if (this != &orig)
		this->setSignature(orig.getSignature());
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig): AForm("Shrubbery Creation", 145, 137), _target(orig._target)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->setSignature(orig.getSignature());
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("Shrubbery Creation", 145, 137), _target(target)
{
	//std::cout << this << " was printed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const ShrubberyCreationForm& paper)
{
	out << paper.getName() << " Form (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}

// EXCEPTIONS

/*ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(const ShrubberyCreationForm &paper, const std::string &reason)
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
}*/