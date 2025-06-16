#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//MEMBER FUNCTIONS

AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	/*void (Intern::*form_method[3])(std::string const &target) = 
	{
		&ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target),
		&RobotomyRequestForm::RobotomyRequestForm(std::string const &target),
		&PresidentialPardonForm::PresidentialPardonForm(std::string const &target),
	};*/
	std::string form_name[3] = 
	{
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon",
	};
	try
	{
		AForm* new_form;
		for (int i = 0; i < 3; i++)
		{
			if (name == form_name[i])
			{
				switch (i)
				{
				case 0:
					new_form = new ShrubberyCreationForm(target);
					break;
				case 1:
					new_form = new RobotomyRequestForm(target);
					break;
				case 2:
					new_form = new PresidentialPardonForm(target);
					break;
				default:
					throw NoFormException();
				}
				std::cout << "Intern created the " << name << "." << std::endl;
				return (new_form);
			}
		}
		throw NoFormException();
	}
	catch (std::exception &e)
	{
		std::cout << name << e.what() << std::endl;
	}
	throw NoFormException();
}

//CONSTRUCTORS & DESTRUCTORS

Intern &Intern::operator = (const Intern &orig)
{
	(void)orig;
	//std::cout << "Some Intern was copy-referred." << std::endl;
	return (*this);
}

Intern::Intern(const Intern &orig)
{
	(void)orig;
	//std::cout << "Some Intern was referred." << std::endl;
}

Intern::Intern(void)
{
	//std::cout << "Some Intern was hired." << std::endl;
}

Intern::~Intern(void)
{
	//std::cout << "Some Intern was fired" << std::endl;
}

// EXCEPTIONS

Intern::NoFormException::NoFormException()
{
	std::ostringstream out;
	out << " does not exist in the Form archives.";
	_msg = out.str();
}

Intern::NoFormException::~NoFormException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Intern::NoFormException::what() const throw()
{
	return (this->_msg.c_str());
}
