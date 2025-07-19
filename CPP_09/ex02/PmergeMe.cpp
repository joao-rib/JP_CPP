#include "PmergeMe.hpp"

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

void 	PmergeMe::validate_input()
{
	this->setInput(trim_whitespace(this->getInput()));
	size_t len = this->getInput().size();
	if (len < 5 || !(len % 2) || !isDigit(this->getInput()[0]) || !isOpToken(this->getInput()[len - 1]))
		throw InputException("");

	// Numbers or operators in even; whitespace in odd
	int j = 1;
	for (unsigned int i = 0; i < this->getInput().size(); i++, j *= -1)
	{ 
		if ((j > 0 && !(isDigit(this->getInput()[i]) || isOpToken(this->getInput()[i])))
			|| (j < 0 && !isDelim(this->getInput()[i])))
			throw InputException("");
	}
}

int		PmergeMe::operation(char op, int fir, int sec)
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
					throw InputException(": Unexpected character");
			}
		}
	}
	return 0;
}

void	PmergeMe::print_result(void)
{
	// Empty input check
	if (this->getInput() == "")
		return ;

	// Calculation process: , then operate when finding an operator
	for (unsigned int i = 0; i < this->getInput().size(); i += 2)
	{
		// Add numbers to the stack
		if (isDigit(this->getInput()[i]))
			this->_numbers.push(this->getInput()[i] - '0');
		else if (isOpToken(this->getInput()[i]))
		{
			// "If too many operators"
			if (this->_numbers.size() < 2)
				throw InputException("");

			// Operate first two numbers from stack, then push the result to the top
			int second = this->_numbers.top();
			this->_numbers.pop();
			int first = this->_numbers.top();
			this->_numbers.pop();
			this->_numbers.push(operation(this->getInput()[i], first, second));
		}
	}

	// "If too many numbers"
	if (this->_numbers.size() != 1)
		throw InputException("");

	// Print result
	std::cout << this->_numbers.top() << std::endl;
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

void	PmergeMe::setInput(std::string input)
{
	this->_input = input;
}

std::string const	&PmergeMe::getInput(void) const
{
	return(this->_input);
}

// |----------------------
// | CONSTRUCTORS & DESTRUCTORS
// |----------------------

PmergeMe &PmergeMe::operator = (const PmergeMe &orig)
{
	if (this != &orig)
	{
		this->_numbers = orig._numbers;
		this->setInput(orig.getInput());
	}
	//std::cout << "PmergeMe assignment copy-constructed." << std::endl;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &orig): _numbers(orig._numbers), _input(orig._input)
{
	//std::cout << "PmergeMe copy-constructed." << std::endl;
}

PmergeMe::PmergeMe(char** input)
{
	this->setInput(input);
	this->validate_input();
	//std::cout << "PmergeMe constructed." << std::endl;
}

PmergeMe::PmergeMe(void)
{
	this->setInput("");
	//std::cout << "Empty PmergeMe constructed." << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "PmergeMe destructed." << std::endl;
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