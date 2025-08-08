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

// |----------------------
// | MEMBER FUNCTIONS
// |----------------------

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
	if (this->_vec_cnt.empty() || this->_deq_cnt.empty())
		return ;

	// Print (Vector)
	std::cout << "After:";
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << " " << this->_vec_cnt[i];
	std::cout << std::endl;

	// This part is commented, but it is good for testing
	// Print (Deque)
/*	std::cout << "After (Deque):";
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << " " << this->_deq_cnt[i];
	std::cout << std::endl;
*/
}

int	PmergeMe::diffJacobsthal(int seq_num)
{
	if (seq_num == 0)
		return 1;
	else if (seq_num == 1)
		return 0;

	int i = 1;
	int s = 0;
	int curr = 0;
	int next = 1;
	while (s < (seq_num - 1))
	{
		curr = next;
		next = curr + curr + i;
		i *= -1;
		s++;
	}
	return (next - curr);
}

int PmergeMe::maxComparisons()
{
	int sum = 0;
	for (size_t k = 1; k <= this->getSize(); ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
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

size_t	PmergeMe::getLayers(void) const
{
	return(this->_last_layer);
}

size_t	PmergeMe::getCompVec(void) const
{
	return(this->_comparisons_vec);
}

size_t	PmergeMe::getCompDeq(void) const
{
	return(this->_comparisons_deq);
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
		_last_layer = 0;
		_comp_tmp = 0;
		this->_input = orig._input;
		//this->_size = orig.getSize();

		setTime(TIME_START);
		for (unsigned int i = 0; i < this->getSize(); i++)
			_vec_cnt.push_back(this->getInput()[i]);
		this->order_container(this->_vec_cnt, 1);
		_comparisons_vec = _comp_tmp;
		setTime(TIME_1);

		setTime(TIME_START);
		for (unsigned int i = 0; i < this->getSize(); i++)
			_deq_cnt.push_back(this->getInput()[i]);
		this->order_container(this->_deq_cnt, 1);
		_comparisons_deq = _comp_tmp;
		setTime(TIME_2);
	}
	//std::cout << "PmergeMe assignment copy-constructed." << std::endl;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &orig): _input(orig._input), _size(orig._size)
{
	_last_layer = 0;
	_comp_tmp = 0;

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_vec_cnt.push_back(this->getInput()[i]);
	this->order_container(this->_vec_cnt, 1);
	_comparisons_vec = _comp_tmp;
	setTime(TIME_1);

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_deq_cnt.push_back(this->getInput()[i]);
	this->order_container(this->_deq_cnt, 1);
	_comparisons_deq = _comp_tmp;
	setTime(TIME_2);

	//std::cout << "PmergeMe copy-constructed." << std::endl;
}

PmergeMe::PmergeMe(char** args, int arg_num): _size(arg_num - 1)
{
	_last_layer = 0;
	this->setInput(args);
	_comp_tmp = 0;

	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_vec_cnt.push_back(this->getInput()[i]);
	this->order_container(this->_vec_cnt, 1);
	_comparisons_vec = _comp_tmp;
	setTime(TIME_1);

	_comp_tmp = 0;;
	setTime(TIME_START);
	for (unsigned int i = 0; i < this->getSize(); i++)
		_deq_cnt.push_back(this->getInput()[i]);
	this->order_container(this->_deq_cnt, 1);
	_comparisons_deq = _comp_tmp;
	setTime(TIME_2);

	//std::cout << "PmergeMe constructed." << std::endl;
}

PmergeMe::PmergeMe(void): _size(0)
{
	_last_layer = 0;
	_input = NULL;
	_comp_tmp = 0;
	_comparisons_deq = 0;
	_comparisons_vec = 0;
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