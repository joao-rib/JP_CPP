#include "Span.hpp"

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

void	Span::addNumber(int num)
{
	if (this->_int_vec.size() == this->_size)
		throw FullSpanException(this->_size);

	this->_int_vec.push_back(num);
	//std::cout << num << " has been added to the integer array." << std::endl;
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int s = this->_int_vec.size();

	if (s <= 1)
		throw NoSpanException();

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

unsigned int	Span::longestSpan(void) const
{
	if (this->_int_vec.size() <= 1)
		throw NoSpanException();

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

Span &Span::operator = (const Span &orig)
{
	if (this != &orig)
	{
		_size = orig._size;
		_int_vec = orig._int_vec;
	}
	//std::cout << "Span assignment copy-constructed." << std::endl;
	return (*this);
}

Span::Span(const Span &orig): _int_vec(orig._int_vec), _size(orig._size)
{
	//std::cout << "Span copy-constructed." << std::endl;
}

Span::Span(unsigned int N): _size(N)
{
	//std::cout << "Span constructed." << std::endl;
}

Span::Span(void): _size(0)
{
	//std::cout << "Span constructed (empty)." << std::endl;
}

Span::~Span(void)
{
	//std::cout << "Span destructed." << std::endl;
}

//
// OVERLOAD OPERATIONS
//

//
// EXCEPTIONS
//

Span::FullSpanException::FullSpanException(unsigned int N)
{
	std::ostringstream out;
	out << "Cannot add more than " << N << " integers.";
	_msg = out.str();
}

Span::FullSpanException::~FullSpanException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Span::FullSpanException::what() const throw()
{
	return (this->_msg.c_str());
}

Span::NoSpanException::NoSpanException()
{
	std::ostringstream out;
	out << "Two integers are needed to find Span.";
	_msg = out.str();
}

Span::NoSpanException::~NoSpanException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Span::NoSpanException::what() const throw()
{
	return (this->_msg.c_str());
}