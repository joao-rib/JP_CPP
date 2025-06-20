#include "ScalarConverter.hpp"

//atoi(const char*)	int	<cstdlib>
//atof(const char*)	double	<cstdlib>
//atol(const char*)	long	<cstdlib>
//strtol(const char*, char**, int)	long with base support	<cstdlib>
//strtod(const char*, char**)	double	<cstdlib>

//HELPER FUNCTIONS

bool	ft_isdelim(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	else
		return (false);
}

std::string parse_input(std::string const &str)
{
	int	i = 0;
	int	l = str.length();
	if (l <= 1)
		return str;
	l--;
	while (i < l && ft_isdelim(str[i]))
		i++;
	while (l > i && ft_isdelim(str[l]))
		l--;
	std::string parsed = str.substr(i, l - i + 1);

	if (str[l] == 'f' )
	{
		char* endptr = 0;
		std::string buff = str.substr(i, l - i);
		std::strtod(buff.c_str(), &endptr); //(void)?
		if (*endptr == 0)
			parsed = str.substr(i, l - i);
	}

	return (parsed);
}

void	printChar(double num)
{
	try
	{
		std::cout << "Char: ";
		if (num < 0 || num > 127)
			throw ScalarConverter::OutsideScopeException("not a character.");
		else if (num < 32 || num == 127)
			throw ScalarConverter::OutsideScopeException("not a printable character.");
		std::cout << static_cast<char>(num) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Input is " << e.what() << std::endl;
	}
	
}

void	printInt(double num)
{
	try
	{
		std::cout << "Int: ";
		if (num > INT_MAX || num < INT_MIN)
			throw ScalarConverter::OutsideScopeException("outside of the acceptable range of int values.");
		std::cout << static_cast<int>(num) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Input is " << e.what() << std::endl;
	}

}

void	printFloat(double num)
{
	std::cout << "Float: ";
	std::cout << static_cast<float>(num) << std::endl;
}

void	printDouble(double num)
{
	std::cout << "Double: ";
	std::cout << num << std::endl;
}

//MEMBER FUNCTIONS

void ScalarConverter::converter(std::string const &str)
{
	std::string buff = parse_input(str);
	// WIP Handle nan
	//char* endptr = 0;
	//double num = strtod(buff.c_str(), &endptr); //WIP averiguar. Que se passa se nao for numero?
	double num = atof(buff.c_str()); //WIP averiguar. Que se passa se nao for numero?
	printChar(num); //WIP more tests.
	printInt(num); //WIP more tests.
	printFloat(num); //WIP more tests. Four decimals?
	printDouble(num); //WIP more tests. Four decimals?
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

ScalarConverter::OutsideScopeException::OutsideScopeException(const std::string &reason)
{
	std::ostringstream out;
	out << reason;
	_msg = out.str();
}

ScalarConverter::OutsideScopeException::~OutsideScopeException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *ScalarConverter::OutsideScopeException::what() const throw()
{
	return (this->_msg.c_str());
}