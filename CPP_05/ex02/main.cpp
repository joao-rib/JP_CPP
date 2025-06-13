#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
try
{
	Bureaucrat	Matrix("Agent Smith", 1);
	Bureaucrat	Hitman("Agent 47", 47);
	Bureaucrat	MIB("Agent J", 142);
	Bureaucrat	goon;
	ShrubberyCreationForm		scf("Av_Aliados");
	RobotomyRequestForm			rrf("Coporob");
	PresidentialPardonForm		ppf("Nelson Mandela");

	std::cout << Matrix << " is on the scene." << std::endl;
	std::cout << Hitman << " is on the scene." << std::endl;
	std::cout << MIB << " is on the scene." << std::endl;
	std::cout << goon << " is on the scene." << std::endl;

	std::cout << "/n" << scf << " needs to be signed and executed." << std::endl;
	MIB.signForm(scf);
	Hitman.signForm(scf);
	goon.signForm(scf);

	std::cout << "/n" << rrf << " needs to be signed and executed." << std::endl;
	MIB.signForm(rrf);
	Hitman.signForm(rrf);
	goon.signForm(rrf);

	std::cout << "/n" << ppf << " needs to be signed and executed." << std::endl;
	MIB.signForm(ppf);
	Hitman.signForm(ppf);
	goon.signForm(ppf);
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}