#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature() == false)
		throw CannotExecuteException(*this, " is not signed.");
	else if (executor.getGrade() > this->getExecGrade())
		throw CannotExecuteException(*this, " cannot be executed by a Bureaucrat of lower grade.");
	// WIP Drilling noises. Then <target> has been robotomized. Or not. 50/50
}

//CONSTRUCTORS & DESTRUCTORS

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &orig)
{
	if (this != &orig)
		this->setSignature(orig.getSignature());
	//std::cout << this << " was fax-photocopied." << std::endl;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig): AForm("Robotomy Request", 72, 45), _target(orig._target)
{
	//std::cout << this << " was photocopied." << std::endl;
	this->setSignature(orig.getSignature());
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("Robotomy Request", 72, 45), _target(target)
{
	//std::cout << this << " was printed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

std::ostream& operator << (std::ostream& out, const RobotomyRequestForm& paper)
{
	out << paper.getName() << " Form (Signature grade " << paper.getSignGrade() << ", Execution grade " << paper.getExecGrade() << ")";
	return (out);
}