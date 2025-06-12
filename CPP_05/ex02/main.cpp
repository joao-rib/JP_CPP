#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
try
{
	Bureaucrat	Matrix("Agent Smith", 1);
	Bureaucrat	Hitman("Agent 47", 47);
	Bureaucrat	MIB("J", 150);
	Bureaucrat	goon;
	ShrubberyCreationForm		scf("Home");

	std::cout << Matrix << " is on the scene." << std::endl;
	std::cout << Hitman << " is on the scene." << std::endl;
	std::cout << MIB << " is on the scene." << std::endl;
	std::cout << goon << " is on the scene." << std::endl;
	std::cout << scf << " needs to be filled." << std::endl;

	MIB.signForm(scf);
	Hitman.signForm(scf);
	goon.signForm(scf);
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}