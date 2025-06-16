#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//HELPER FUNCTIONS

AForm*	makeShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	makeRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	makePardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

std::string capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

//MEMBER FUNCTIONS

AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm* (*form_method[])(std::string const &target) = 
	{
		makeShrubbery,
		makeRobotomy,
		makePardon,
	};
	const std::string form_name[] = 
	{
		"SHRUBBERY CREATION",
		"ROBOTOMY REQUEST",
		"PRESIDENTIAL PARDON",
	};
	
	//AForm* new_form;
	for (int i = 0; i < 3; i++)
	{
		if (capitalize(name) == form_name[i])
		{
			/*switch (i)
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
				throw NoFormException(name);
			}*/
			std::cout << "Intern created the " << name << "." << std::endl;
			return (form_method[i](target));
		}
	}
	throw NoFormException(name);
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

Intern::NoFormException::NoFormException(std::string const &name)
{
	std::ostringstream out;
	out << name << " does not exist in the Form archives.";
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
