#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature() == false)
		throw CannotExecuteException(*this, " is not signed.");
	else if (executor.getGrade() > this->getExecGrade())
		throw CannotExecuteException(*this, " cannot be executed by a Bureaucrat of lower grade.");
	std::cout << this->_target << " has been pardoned by His Majesty, El Presidente CEO Supreme Zaphod Beeblebrox." << std::endl;
}

//CONSTRUCTORS & DESTRUCTORS

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &orig)
{
	if (this != &orig)
		this->setSignature(orig.getSignature());
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig): AForm("Presidential Pardon", 25, 5), _target(orig._target)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->setSignature(orig.getSignature());
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("Presidential Pardon", 25, 5), _target(target)
{
	//std::cout << this << " was printed." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const PresidentialPardonForm& paper)
{
	out << paper.getName() << " Form (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}