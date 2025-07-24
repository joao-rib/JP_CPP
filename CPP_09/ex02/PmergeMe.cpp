#include "PmergeMe.hpp"

// |----------------------
// | HELPER FUNCTIONS
// |----------------------

long	currentTime_usec(void)
{
	//std::time_t now = std::time(0);
	//return (now);

	timeval tv;
	if (gettimeofday(&tv, NULL))
		throw InputException(": Problem with gettimeofday()");
	return ((tv.tv_sec * 1000000) + tv.tv_usec);

	/*std::clock_t start = std::clock();
	// program
	std::clock_t end = std::clock();
	double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;*/
}

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

/*bool	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}*/


// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

void	PmergeMe::order_vector(std::vector<int> above)
{
	/*if (above.size() < 2)
		return ;
	// STEP 1: Swap values, Make pairs
	std::vector<int>::iterator it = above.begin();
	std::vector<int> below;
	for (unsigned int i = 0; i < (this->getSize() - 1); i =+ 2, it += 2)
	{
		if (it < (it + 1)) // WIP it.value()
			swap(it, it + 1);
		below.push_back(std::make_pair(it, it + 1));
	}
	order_vector(below);*/
	(void)above;
	// STEP 2: main and pend
	// WIP std::vector main;
	// WIP std::vector pend;

	// STEP 3: Jacobsthal

}

void	PmergeMe::order_deque(std::deque<int> above)
{
	(void)above; // WIP algorithm
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

void	PmergeMe::print_sorted(void)
{
	// Empty variable check
	if (this->_first.empty() || this->_second.empty())
		return ;

	// Print
	std::cout << "After:";
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << " " << this->_first[i]; // From Vector
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
		if (this->_input[i] > INT_MAX)
			throw InputException(": Number above INT_MAX (2147483647)");
	}
}

void	PmergeMe::setTime(t_times option)
{
	switch (option)
	{
	case TIME_1:
		this->_time1 = currentTime_usec() - this->_start_time;
		break ;
	case TIME_2:
		this->_time2 = currentTime_usec() - this->_start_time;
		break ;
	case TIME_START:
		this->_start_time = currentTime_usec();
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

long	PmergeMe::getTime(t_times option) const
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

		setTime(TIME_START);
		for (unsigned int i = 0; i < this->getSize(); i++)
			_first.push_back(this->getInput()[i]);
		this->order_vector(_first);
		setTime(TIME_1);

		setTime(TIME_START);
		for (unsigned int i = 0; i < this->getSize(); i++)
			_second.push_back(this->getInput()[i]);
		this->order_deque(_second);
		setTime(TIME_2);
	}
	//std::cout << "PmergeMe assignment copy-constructed." << std::endl;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &orig): _input(orig._input), _size(orig._size)
{
	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_first.push_back(this->getInput()[i]);
	this->order_vector(_first);
	setTime(TIME_1);

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_second.push_back(this->getInput()[i]);
	this->order_deque(_second);
	setTime(TIME_2);

	//std::cout << "PmergeMe copy-constructed." << std::endl;
}

PmergeMe::PmergeMe(char** args, int arg_num): _size(arg_num - 1)
{
	this->setInput(args);

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_first.push_back(this->getInput()[i]);
	this->order_vector(_first);
	setTime(TIME_1);

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_second.push_back(this->getInput()[i]);
	this->order_deque(_second);
	setTime(TIME_2);

	//std::cout << "PmergeMe constructed." << std::endl;
}

PmergeMe::PmergeMe(void): _size(0)
{
	_input = NULL;
	setTime(TIME_START);
	setTime(TIME_1);
	setTime(TIME_2);
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