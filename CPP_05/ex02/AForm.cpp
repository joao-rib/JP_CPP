#include "AForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	AForm::beSigned(Bureaucrat &bureau)
{
	if (this->_signature == true)
		throw CannotSignException(*this, " is already signed.");
	else if (bureau.getGrade() > this->getSignGrade())
		throw CannotSignException(*this, " cannot be signed by a Bureaucrat of lower grade.");
	this->setSignature(true);
}

//GETTERS & SETTERS

int const &AForm::getSignGrade(void) const
{
	return (this->_grade_sign);
}

int const &AForm::getExecGrade(void) const
{
	return (this->_grade_exec);
}

std::string const &AForm::getName(void) const
{
	return (this->_name);
}

bool const &AForm::getSignature(void) const
{
	return (this->_signature);
}

void AForm::setSignature(bool sign)
{
	this->_signature = sign;
}

//CONSTRUCTORS & DESTRUCTORS

AForm &AForm::operator = (const AForm &orig)
{
	if (this != &orig)
		this->_signature = orig.getSignature();
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

AForm::AForm(const AForm &orig): _name(orig._name), _grade_sign(orig._grade_sign), _grade_exec(orig._grade_exec)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->_signature = orig.getSignature();
}

AForm::AForm(std::string const &name, int grade_sign, int grade_exec): _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException(*this, " cannot be higher than 1.");
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException(*this, " cannot be lower than 150.");
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

AForm::AForm(void): _name("Generic"), _grade_sign(150), _grade_exec(150)
{
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

AForm::~AForm(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const AForm& paper)
{
	out << paper.getName() << " Form (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}

// EXCEPTIONS

AForm::GradeTooHighException::GradeTooHighException(const AForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const AForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
}

AForm::CannotSignException::CannotSignException(const AForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

AForm::CannotSignException::~CannotSignException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *AForm::CannotSignException::what() const throw()
{
	return (this->_msg.c_str());
}

AForm::CannotExecuteException::CannotExecuteException(const AForm &paper, const std::string &reason)
{
	std::ostringstream out;
	out << paper << reason;
	_msg = out.str();
}

AForm::CannotExecuteException::~CannotExecuteException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *AForm::CannotExecuteException::what() const throw()
{
	return (this->_msg.c_str());
}