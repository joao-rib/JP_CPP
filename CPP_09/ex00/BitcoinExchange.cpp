#include "BitcoinExchange.hpp"

// |----------------------
// | HELPER FUNCTIONS
// |----------------------

bool	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	isDate(std::string str)
{
	// Syntax
	if (str.size() != 10)
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);
	for (unsigned int i = 0; i < 10; i++) {
		if ((i == 4 || i == 7) && str[i] != '-')
			return (false);
		else if ((i == 4 || i == 7) && str[i] == '-')
			;
		else if (!isDigit(str[i]))
			return (false);
	}

	// Number validation
	if (std::atoi(str.substr(5, 2).c_str()) > 12 || std::atoi(str.substr(8, 2).c_str()) > 31)
		return (false);
	// WIP more robust date-checking

	return (true);
}

// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

void	BitcoinExchange::print_values()
{
try
{
	; // WIP write function
}
catch (std::exception &e)
{
	std::cerr << "Error: " << e.what() << std::endl;
}
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

void	BitcoinExchange::store_data()
{
	; // WIP write function
}

void	BitcoinExchange::store_input(std::string input)
{
	; // WIP write function
}

// |----------------------
// | CONSTRUCTORS & DESTRUCTORS
// |----------------------

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &orig)
{
	if (this != &orig)
	{
		this->_size = orig._size;
		this->_data = orig._data;
		this->_input = orig._input;
	}
	//std::cout << "BitcoinExchange assignment copy-constructed." << std::endl;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig): _data(orig._data), _input(orig._input), _size(orig._size)
{
	//std::cout << "BitcoinExchange copy-constructed." << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string input)
{
	this->store_data();
	this->store_input(input);
	//std::cout << "BitcoinExchange constructed." << std::endl;
}

BitcoinExchange::BitcoinExchange(void)
{
	this->store_data();
	//std::cout << "BitcoinExchange constructed." << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange destructed." << std::endl;
}

// |----------------------
// | OVERLOAD OPERATIONS
// |----------------------


// |----------------------
// | EXCEPTIONS
// |----------------------

InputException::InputException(std::string msg)
{
	std::ostringstream out;
	out << msg;
	_msg = out.str();
}

InputException::~InputException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *InputException::what() const throw()
{
	return (this->_msg.c_str());
}