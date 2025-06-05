#include "Form.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	Form::beSigned(Bureaucrat bureau)
{
	if (this->_signature = true)
		std::cout << this << " is already signed." << std::endl;
	else if (bureau.getGrade() <= this->getSignGrade())
	{
		this->_signature = true;
		std::cout << bureau << " signed " << this << "." << std::endl;
	}
	else
		throw GradeTooLowException(*this); // WIP
}

//GETTERS & SETTERS

int const &Form::getSignGrade(void) const
{
	return (this->_grade_sign);
}

int const &Form::getExecGrade(void) const
{
	return (this->_grade_exec);
}

std::string const &Form::getName(void) const
{
	return (this->_name);
}

bool const &Form::getSignature(void) const
{
	return (this->_signature);
}

//CONSTRUCTORS & DESTRUCTORS

Form &Form::operator = (const Form &orig)
{
	if (this != &orig)
		this->_signature = orig.getSignature();
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

Form::Form(const Form &orig): _name(orig._name), _grade_sign(orig._grade_sign), _grade_exec(orig._grade_exec)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->_signature = orig.getSignature();
}

Form::Form(std::string const &name, int grade_sign, int grade_exec): _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException(*this);
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException(*this);
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

Form::Form(void): _name("Generic"), _grade_sign(150), _grade_exec(150)
{
	this->_signature = false;
	//std::cout << this << " was printed." << std::endl;
}

Form::~Form(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const Form& paper)
{
	out << paper.getName() << " Form (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}

// EXCEPTIONS

Form::GradeTooHighException::GradeTooHighException(const Form &paper)
{
	std::ostringstream out;
	out << paper << " shows grade higher than 1.";
	_msg = out.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const Form &paper)
{
	std::ostringstream out;
	out << paper << " shows lower than 150.";
	_msg = out.str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
}