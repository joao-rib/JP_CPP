#include "Bureaucrat.hpp"

int	main()
{
try
{
	Bureaucrat	Matrix("Agent Smith", 1);
	Bureaucrat	Hitman("Agent 47", 47);
	Bureaucrat	MIB("J", 150);
	Bureaucrat	goon;

	std::cout << Matrix << " is on the scene." << std::endl;
	std::cout << Hitman << " is on the scene." << std::endl;
	std::cout << MIB << " is on the scene." << std::endl;
	std::cout << goon << " is on the scene." << std::endl;

	Hitman.incGrade();
	std::cout << Hitman << " is mismatched in grade." << std::endl;
	Hitman.decGrade();
	std::cout << Hitman << " is back in the correct grade." << std::endl;

	//Bureaucrat	NEO("Keanu", 0);
	//Bureaucrat	France("Glass Joe", 151);
	//Matrix.incGrade();
	//goon.decGrade();
}
catch (std::exception &e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
	return 0;
}