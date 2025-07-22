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


// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

void 	PmergeMe::validate_input() // WIP write function
{
	/*this->setInput(trim_whitespace(this->getInput()));
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
	}*/
	;
	// WIP check negatives ("Error" only)
	// WIP check non-numbers
	// WIP check duplicates
}

void	PmergeMe::order_vector(int *input)
{
	; // WIP write function
}

void	PmergeMe::order_deque(int *input)
{
	; // WIP write function
}

void	PmergeMe::print_unsorted(void) // WIP write function
{
	/*// Empty input check
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
	std::cout << this->_numbers.top() << std::endl;*/
	;
}

void	PmergeMe::print_sorted(void) // WIP write function
{
	/*// Empty input check
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
	std::cout << this->_numbers.top() << std::endl;*/
	;
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

void	PmergeMe::setInput(char **args)
{
	; // WIP write function
	// WIP check negatives ("Error" only)
	// WIP check non-numbers
	// WIP check duplicates
}

void	PmergeMe::setTime(unsigned double time, t_times option)
{
	switch (option)
	{
	case TIME_1:
		this->_time1 = time;
		break ;
	case TIME_2:
		this->_time2 = time;
		break ;
	case TIME_START:
		this->_start_time = time;
		break ;
	default:
		throw InputException(": Unknown Time Request");
	}
	return ;
}

size_t const	&PmergeMe::getSize(void) const
{
	return(this->_size);
}

unsigned double const	&PmergeMe::getTime(t_times option) const
{
	switch (option)
	{
	case TIME_1:
		return (this->_time1);
	case TIME_2:
		return (this->_time2);
	case TIME_START:
		return (0);
	default:
		throw InputException(": Unknown Time Request");
	}
	return (0);
}

// |----------------------
// | CONSTRUCTORS & DESTRUCTORS
// |----------------------

PmergeMe &PmergeMe::operator = (const PmergeMe &orig)
{
	if (this != &orig)
	{
		this->_input = orig._input();
		this->_size = orig.getSize();
		setTime(orig._start_time, TIME_START); // WIP current time
		this->order_vector();
		this->order_deque();
	}
	//std::cout << "PmergeMe assignment copy-constructed." << std::endl;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &orig): _input(orig._input)
{
	this->_size = orig.getSize();
	setTime(orig._start_time, TIME_START); // WIP current time
	this->order_vector();
	this->order_deque();
	//std::cout << "PmergeMe copy-constructed." << std::endl;
}

PmergeMe::PmergeMe(char** args)
{
	this->setInput(args);
	this->validate_input();
	setTime(0, TIME_START); // WIP current time
	this->order_vector();
	this->order_deque();
	//std::cout << "PmergeMe constructed." << std::endl;
}

PmergeMe::PmergeMe(void)
{
	_input = NULL;
	_size = 0;
	setTime(0, TIME_START); // WIP current time
	setTime(0, TIME_1);
	setTime(0, TIME_2);
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