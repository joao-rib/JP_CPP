#include "RPN.hpp"

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

std::string	trim_whitespace(const std::string& str)
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

bool	isOpToken(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}


// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

int		RPN::operation(char op, int fir, int sec)
{
	std::string	ops = "+-*/";

	for (unsigned int i = 0; i < 4; i++)
	{
		if (ops[i] == op)
		{
			switch (i)
			{
				case 0:
					return (fir + sec);
				case 1:
					return (fir - sec);
				case 2:
					return (fir * sec);
				case 3:
					return (fir / sec);
				default:
					throw InputException("Unexpected character");
			}
		}
	}
	return 0;
}

void	RPN::print_result(void)
{
	// WIP Incorrect method, but it's a start
	// "2 8 + 5 /"
	// "1 2 * 2 / 2 * 2 4 - +"
	while (this->_numbers.size() > 1 || !this->_operators.empty())
	{
		int second = this->_numbers.top();
		this->_numbers.pop();
		int first = this->_numbers.top();
		this->_numbers.pop();
		char op = this->_operators.top();
		this->_operators.pop();

		this->_numbers.push(operation(op, first, second));
	}

	std::cout << this->_numbers.top() << std::endl;
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

void	RPN::set_stacks(std::string input)
{
	// Empty input check
	if (input == "")
		return ;

	// Push tokens
	for (unsigned int i = 0; i < input.size(); i += 2)
	{ 
		if (isDigit(input[i]))
			this->_numbers.push(input[i] - '0');
		else if (isOpToken(input[i]))
			this->_operators.push(input[i]);
	}

	// Basic input check
	if (this->_numbers.size() != (this->_operators.size() + 1))
		throw InputException("");
}

// |----------------------
// | CONSTRUCTORS & DESTRUCTORS
// |----------------------

RPN &RPN::operator = (const RPN &orig)
{
	if (this != &orig)
	{
		this->_numbers = orig._numbers;
		this->_operators = orig._operators;
	}
	//std::cout << "RPN assignment copy-constructed." << std::endl;
	return (*this);
}

RPN::RPN(const RPN &orig): _numbers(orig._numbers), _operators(orig._operators)
{
	//std::cout << "RPN copy-constructed." << std::endl;
}

RPN::RPN(std::string input)
{
	this->set_stacks(input);
	//std::cout << "RPN constructed." << std::endl;
}

RPN::RPN(void)
{
	this->set_stacks("");
	//std::cout << "RPN constructed." << std::endl;
}

RPN::~RPN(void)
{
	//std::cout << "RPN destructed." << std::endl;
}

// |----------------------
// | OVERLOAD OPERATIONS
// |----------------------

// |----------------------
// | EXCEPTIONS
// |----------------------

/*RPN::InvalidValueException::InvalidValueException(std::string msg, std::string value)
{
	std::ostringstream out;
	out << msg << value;
	_msg = out.str();
}

RPN::InvalidValueException::~InvalidValueException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *RPN::InvalidValueException::what() const throw()
{
	return (this->_msg.c_str());
}*/

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