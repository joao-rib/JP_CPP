#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
try
{
	Bureaucrat	Matrix("Agent Smith", 1);
	Bureaucrat	Hitman("Agent 47", 47);
	Bureaucrat	MIB("J", 150);
	Bureaucrat	goon;
	Form		IRS("Impostos", 149, 2);
	Form		Job_opening("Candidatura 42", 42, 42);

	std::cout << Matrix << " is on the scene." << std::endl;
	std::cout << Hitman << " is on the scene." << std::endl;
	std::cout << MIB << " is on the scene." << std::endl;
	std::cout << goon << " is on the scene." << std::endl;
	std::cout << IRS << " needs to be filled." << std::endl;
	std::cout << Job_opening << " needs to be filled." << std::endl;

	Hitman.signForm(IRS);
	goon.signForm(IRS);
	//Hitman.signForm(Job_opening);
	Matrix.signForm(Job_opening);
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}