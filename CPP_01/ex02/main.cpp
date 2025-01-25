# include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory addresses:\n";
	std::cout << "string variable: " << &string << "\n";
	std::cout << "stringPTR: " << stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "\nValues:\n";
	std::cout << "string variable: " << string << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF: " << stringREF << std::endl;

	/*stringREF = stringPTR;
	std::cout << "\nstring variable: " << string << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF new: " << stringREF << std::endl;
	stringREF = "Tutti Frutti";
	std::cout << "string variable: " << string << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF new: " << stringREF << std::endl;*/
	return(0);
}
