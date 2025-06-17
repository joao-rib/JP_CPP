#include "ScalarConverter.hpp"

//atoi(const char*)	int	<cstdlib>
//atof(const char*)	double	<cstdlib>
//atol(const char*)	long	<cstdlib>
//strtol(const char*, char**, int)	long with base support	<cstdlib>
//strtod(const char*, char**)	double	<cstdlib>

//HELPER FUNCTIONS

std::string const &printChar(double num)
{
	try
	{
		if (num < 0 || num > 127)
			throw noCharException(" not a character.");
		else if (num < 32 || num == 127)
			throw noCharException(" not a printable character.");
		std::cout << "Char: " << static_cast<char>(num) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Input is " << e.what() << std::endl;
	}
	
}

std::string const &printInt(double num)
{

}

std::string const &printFloat(double num)
{

}

std::string const &printDouble(double num)
{

}

void ScalarConverter::converter(std::string const &str)
{
	double num = atof(str.c_str()); //WIP averiguar
	std::cout << "Char: " << printChar(num) << std::endl; //WIP tochar
	std::cout << "Int: " << printInt(num) << std::endl; //WIP toint
	std::cout << "Float: " << printFloat(num) << std::endl; //WIP tofloat
	std::cout << "Double: " << printDouble(num) << std::endl; //WIP todouble
}

//GETTERS & SETTERS

//CONSTRUCTORS & DESTRUCTORS

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &orig)
{
	(void)orig;
	//std::cout << "Some ScalarConverter was copy-referred." << std::endl;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
	(void)orig;
	//std::cout << "Some ScalarConverter was referred." << std::endl;
}

ScalarConverter::ScalarConverter(void)
{
	//std::cout << "Some ScalarConverter was hired." << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "Some ScalarConverter was fired" << std::endl;
}

//OVERLOAD OPERATIONS

//EXCEPTIONS

ScalarConverter::NoCharException::NoCharException(const std::string &reason)
{
	std::ostringstream out;
	out << reason;
	_msg = out.str();
}

ScalarConverter::NoCharException::~NoCharException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *ScalarConverter::NoCharException::what() const throw()
{
	return (this->_msg.c_str());
}