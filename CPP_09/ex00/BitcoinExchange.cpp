#include "BitcoinExchange.hpp"

// |----------------------
// | HELPER FUNCTIONS
// |----------------------

bool	isDelim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	else
		return (false);
}

const std::string	trim_whitespace(const std::string& str)
{
	int i = 0;
	while (isDelim(str[i]))
		i++;
	if (!str[i])
		return ("");

	size_t j = str.size() - 1;
	while (isDelim(str[j]))
		j--;
	return (str.substr(i, j - i + 1));
}

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
	std::map<std::string, float>::iterator it = this->_input.begin();

	for (unsigned int i = 0; i < this->size(); i++, it++)
	{
	try
	{
		// WIP store_input() is not saving duplicates!!
		if (!isDate(it->first) || it->second == 0)
			throw InvalidValueException("bad input => ", it->first);
		else if (it->second < 0)
			throw InvalidValueException("not a positive number.", "");
		else if (it->second > 1000)
			throw InvalidValueException("too large a number.", "");
		float exchanged = it->second * this->_data[it->first];
		// WIP If date is not in data, find closest lower date
		std::cout << it->first << " => " << it->second << " => " << exchanged << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	}
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

unsigned int const	&BitcoinExchange::size(void) const
{
	return (this->_size);
}

void	BitcoinExchange::incSize(void)
{
	this->_size++;
}

void	BitcoinExchange::store_data(void)
{
	std::ifstream	data("./data.csv");
	std::string		line;

	getline(data, line);
	if (line != "date,exchange_rate")
		throw InputException("data.csv lacks proper header (date,exchange_rate)");

	while(getline(data, line))
	{
		size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue ;
		std::string date = trim_whitespace(line.substr(0, sep));
		char* safeguard;
		this->_data[date] = std::strtof(trim_whitespace(line.substr(sep + 1, line.size() - sep)).c_str(), &safeguard);
		if (date == safeguard || *safeguard != '\0')
			throw InputException("data.csv is not properly formatted");
	}
	data.close();
}

void	BitcoinExchange::store_input(std::string input)
{
	std::ifstream	inp(input.c_str());
	std::string		line;

	getline(inp, line);
	if (line != "date | value")
		throw InputException("Argument file lacks proper header (date | value)");

	while(getline(inp, line))
	{
		size_t	sep = line.find('|');
		if (sep == std::string::npos)
			this->_input[line.substr(0, line.size())] = 0;
		else
		{
			std::string date = trim_whitespace(line.substr(0, sep));
			char* safeguard;
			this->_input[date] = std::strtof(trim_whitespace(line.substr(sep + 1, line.size() - sep)).c_str(), &safeguard);
			if (date == safeguard || *safeguard != '\0')
				this->_input[date] = 0;
		}
		this->incSize();
	}
	inp.close();
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
	this->_size = 0;
	this->store_input(input);
	//std::cout << "BitcoinExchange constructed." << std::endl;
}

BitcoinExchange::BitcoinExchange(void)
{
	this->store_data();
	this->_size = 0;
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

BitcoinExchange::InvalidValueException::InvalidValueException(std::string msg, std::string value)
{
	std::ostringstream out;
	out << msg << value;
	_msg = out.str();
}

BitcoinExchange::InvalidValueException::~InvalidValueException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *BitcoinExchange::InvalidValueException::what() const throw()
{
	return (this->_msg.c_str());
}

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