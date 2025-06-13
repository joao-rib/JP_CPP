#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//MEMBER FUNCTIONS

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature() == false)
		throw CannotExecuteException(*this, " is not signed.");
	else if (executor.getGrade() > this->getExecGrade())
		throw CannotExecuteException(*this, " cannot be executed by a Bureaucrat of lower grade.");

	std::string newFileName = this->_target + "_shrubbery";
	std::ofstream newFile(newFileName.c_str());
	if (!newFile.is_open())
		throw CannotExecuteException(*this, " the shrubbery file could not be opened.");

	newFile << "        ^        " << std::endl;
	newFile << "       $$$       " << std::endl;
	newFile << "      $$$$$      " << std::endl;
	newFile << "     $$$$$$$     " << std::endl;
	newFile << "    $$$$$$$$$    " << std::endl;
	newFile << "   $$$$$$$$$$$   " << std::endl;
	newFile << "  $$$$$$$$$$$$$  " << std::endl;
	newFile << " $$$$$$$$$$$$$$$ " << std::endl;
	newFile << "       |||       " << std::endl;
	newFile << "       |||       " << std::endl;

	newFile.close();
}

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
