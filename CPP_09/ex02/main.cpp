#include "PmergeMe.hpp"

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
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
*/