#include "BitcoinExchange.hpp"

//
//HELPER FUNCTIONS
//

unsigned int	diff(int a, int b)
{
	int r = a - b;
	if (r < 0)
		r *= -1;
	return (static_cast<unsigned int>(r));
}

//
//MEMBER FUNCTIONS
//

void	BitcoinExchange::addNumber(int num)
{
	if (this->_int_vec.size() == this->_size)
		throw FullBitcoinExchangeException(this->_size);

	this->_int_vec.push_back(num);
	//std::cout << num << " has been added to the integer array." << std::endl;
}

void	BitcoinExchange::addManyRandomNumbers(unsigned int num)
{
	unsigned int rem = this->_size - this->_int_vec.size();

	if (num > rem)
		throw FullBitcoinExchangeException(rem);

	srand(time(NULL));
	for (unsigned int i = 0; i < num; i++) {
		this->addNumber(rand());
	}
	//std::cout << num << " integers have been added to the integer array." << std::endl;
}

unsigned int	BitcoinExchange::shortestBitcoinExchange(void) const
{
	unsigned int s = this->_int_vec.size();

	if (s <= 1)
		throw NoBitcoinExchangeException();

	unsigned int r = diff(this->_int_vec[0], this->_int_vec[1]);

	for (unsigned int i = 0; i < s; i++)
	{
		for (unsigned int j = 0; j < s; j++)
		{
			if (i == j)
				continue ;
			else if (diff(_int_vec[i], _int_vec[j]) < r)
				r = diff(_int_vec[i], _int_vec[j]);
		}
	}
	return (r);
}

unsigned int	BitcoinExchange::longestBitcoinExchange(void) const
{
	if (this->_int_vec.size() <= 1)
		throw NoBitcoinExchangeException();

	std::vector<int>::const_iterator min = std::min_element(_int_vec.begin(), _int_vec.end());
	std::vector<int>::const_iterator max = std::max_element(_int_vec.begin(), _int_vec.end());

	return (diff(*min, *max));
}

//
//GETTERS & SETTERS
//

//
//CONSTRUCTORS & DESTRUCTORS
//

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &orig)
{
	if (this != &orig)
	{
		_size = orig._size;
		_int_vec = orig._int_vec;
	}
	//std::cout << "BitcoinExchange assignment copy-constructed." << std::endl;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig): _int_vec(orig._int_vec), _size(orig._size)
{
	//std::cout << "BitcoinExchange copy-constructed." << std::endl;
}

BitcoinExchange::BitcoinExchange(unsigned int N): _size(N)
{
	//std::cout << "BitcoinExchange constructed." << std::endl;
}

BitcoinExchange::BitcoinExchange(void): _size(0)
{
	//std::cout << "BitcoinExchange constructed (empty)." << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange destructed." << std::endl;
}

//
// OVERLOAD OPERATIONS
//

int	&BitcoinExchange::operator [] (long index)
{
	if (static_cast<unsigned long>(index) >= this->_int_vec.size() || index < 0)
		throw OutOfBoundsException(*this, index);
	return (_int_vec[index]);
}

const int	&BitcoinExchange::operator [] (long index) const
{
	if (static_cast<unsigned long>(index) >= this->_int_vec.size() || index < 0)
		throw OutOfBoundsException(*this, index);
	return (_int_vec[index]);
}

//
// EXCEPTIONS
//

BitcoinExchange::FullBitcoinExchangeException::FullBitcoinExchangeException(unsigned int N)
{
	std::ostringstream out;
	out << "Cannot add more than " << N << " integers.";
	_msg = out.str();
}

BitcoinExchange::FullBitcoinExchangeException::~FullBitcoinExchangeException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *BitcoinExchange::FullBitcoinExchangeException::what() const throw()
{
	return (this->_msg.c_str());
}

BitcoinExchange::NoBitcoinExchangeException::NoBitcoinExchangeException()
{
	std::ostringstream out;
	out << "Two integers are needed to find BitcoinExchange.";
	_msg = out.str();
}

BitcoinExchange::NoBitcoinExchangeException::~NoBitcoinExchangeException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *BitcoinExchange::NoBitcoinExchangeException::what() const throw()
{
	return (this->_msg.c_str());
}

BitcoinExchange::OutOfBoundsException::OutOfBoundsException(const BitcoinExchange &arr, long pos)
{
	std::ostringstream out;
	out << "Position "<< pos << " lies outside of the bounds of a container of size " << arr._size;
	_msg = out.str();
}

BitcoinExchange::OutOfBoundsException::~OutOfBoundsException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *BitcoinExchange::OutOfBoundsException::what() const throw()
{
	return (this->_msg.c_str());
}