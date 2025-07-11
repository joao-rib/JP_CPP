#include "RPN.hpp"

int	main()
{
try
{
	Bureaucrat	Matrix("Agent Smith", 1);
	Bureaucrat	Hitman("Agent 47", 47);
	Bureaucrat	MIB("Agent J", 142);
	Bureaucrat	goon;
	ShrubberyCreationForm		scf("Av_Aliados");		// Sign 145, Exec 137
	//RobotomyRequestForm			rrf("Coporob");			// Sign 72, Exec 45
	PresidentialPardonForm		ppf("Nelson Mandela");	// Sign 25, Exec 5

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << Matrix << " is on the scene." << std::endl;
	std::cout << Hitman << " is on the scene." << std::endl;
	std::cout << MIB << " is on the scene." << std::endl;
	std::cout << goon << " is on the scene." << std::endl;

	std::cout << std::endl << scf << " needs to be signed and executed." << std::endl; // Sign 145, Exec 137
	Hitman.executeForm(scf);
	goon.signForm(scf);
	MIB.signForm(scf);
	Hitman.signForm(scf);
	MIB.executeForm(scf);
	Hitman.executeForm(scf);

	std::cout << std::endl << *rrf << " needs to be signed and executed." << std::endl; // Sign 72, Exec 45
	Hitman.executeForm(*rrf);
	MIB.signForm(*rrf);
	Hitman.signForm(*rrf);
	Hitman.executeForm(*rrf);
	Matrix.executeForm(*rrf);
	delete rrf;

	std::cout << std::endl << ppf << " needs to be signed and executed." << std::endl; // Sign 25, Exec 5
	Matrix.executeForm(ppf);
	Hitman.signForm(ppf);
	Matrix.signForm(ppf);
	Hitman.executeForm(ppf);
	Matrix.executeForm(ppf);
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}

//Output example
/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
*/