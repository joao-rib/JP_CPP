#include "PmergeMe.hpp"

// |----------------------
// | HELPER FUNCTIONS
// |----------------------

bool	isDelim(char c) // WIP check if redundant
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	else
		return (false);
}

std::string	trim_whitespace(const std::string& str) // WIP check if redundant
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

bool	isDigit(char c) // WIP check if redundant
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}


// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

/*void 	PmergeMe::validate_input() // WIP write function
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
	// WIP check negatives ("Error" only)
}*/

void	PmergeMe::order_vector(void)
{
	/*for (unsigned int i = 0; i < this->getSize(); i =+ 2)
	{
		if ()
			;
	}
		_first.push_back(this->getInput()[i]);*/

	//std::vector main;
	//std::vector pend;
	; // WIP algorithm
}

void	PmergeMe::order_deque(void)
{
	; // WIP algorithm
}

void	PmergeMe::print_unsorted(void)
{
	// Empty variable check
	if (!this->getInput())
		return ;

	// Print
	std::cout << "Before:";
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << " " << this->getInput()[i];
	std::cout << std::endl;
}

void	PmergeMe::print_sorted(void) // WIP write function
{
	// Empty variable check
	if (this->_first.empty() || this->_second.empty())
		return ;

	// Print
	std::cout << "After:";
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << " " << this->_first[i];
	std::cout << std::endl;
}

// |----------------------
// | GETTERS & SETTERS
// |----------------------

void	PmergeMe::setInput(char **args)
{
	char* safeguard = 0;
	this->_input = new int[this->getSize()];
	for (unsigned int i = 0; i < this->getSize(); i++)
	{
		this->_input[i] = static_cast<int>(std::strtod(trim_whitespace(args[i + 1]).c_str(), &safeguard));
		if (args[i] == safeguard || *safeguard != '\0')
			throw InputException(": Invalid arguments");
		if (this->_input[i] < 0)
			throw InputException("");
	}
	// WIP check duplicates?
}

void	PmergeMe::setTime(unsigned int time, t_times option)
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

int *const	&PmergeMe::getInput(void) const
{
	return(this->_input);
}

size_t const	&PmergeMe::getSize(void) const
{
	return(this->_size);
}

unsigned int	PmergeMe::getTime(t_times option) const
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
		this->_input = orig._input;
		//this->_size = orig.getSize();
		setTime(orig._start_time, TIME_START); // WIP current time
		for (unsigned int i = 0; i < this->getSize(); i++)
			_first.push_back(this->getInput()[i]);
		this->order_vector();
		setTime(orig._start_time, TIME_START); // WIP current time
		for (unsigned int i = 0; i < this->getSize(); i++)
			_second.push_back(this->getInput()[i]);
		this->order_deque();
	}
	//std::cout << "PmergeMe assignment copy-constructed." << std::endl;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &orig): _input(orig._input), _size(orig._size)
{
	//this->_size = orig.getSize();
	setTime(orig._start_time, TIME_START); // WIP current time
	for (unsigned int i = 0; i < this->getSize(); i++)
		_first.push_back(this->getInput()[i]);
	this->order_vector();
	setTime(orig._start_time, TIME_START); // WIP current time
	for (unsigned int i = 0; i < this->getSize(); i++)
		_second.push_back(this->getInput()[i]);
	this->order_deque();
	//std::cout << "PmergeMe copy-constructed." << std::endl;
}

PmergeMe::PmergeMe(char** args, int arg_num): _size(arg_num - 1)
{
	this->setInput(args);
	//this->validate_input();
	setTime(0, TIME_START); // WIP current time
	for (unsigned int i = 0; i < this->getSize(); i++)
		_first.push_back(this->getInput()[i]);
	this->order_vector();
	setTime(0, TIME_START); // WIP current time
	for (unsigned int i = 0; i < this->getSize(); i++)
		_second.push_back(this->getInput()[i]);
	this->order_deque();
	//std::cout << "PmergeMe constructed." << std::endl;
}

PmergeMe::PmergeMe(void): _size(0)
{
	_input = NULL;
	setTime(0, TIME_START); // WIP current time
	setTime(0, TIME_1);
	setTime(0, TIME_2);
	//std::cout << "Empty PmergeMe constructed." << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	delete[] this->_input;
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