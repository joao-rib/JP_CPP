#include "Span.hpp"

//
//HELPER FUNCTIONS
//

//
//MEMBER FUNCTIONS
//

void	Span::addNumber(int num)
{
	try
	{
		if (this->_int_vec.size() == this->N)
			throw FullSpanException(this->_size);
		this->_int_vec.push_back(num);
		std::cout << num << " has been added to the integer array." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
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
		_int_vec = orig._int_vect;
	}
	//std::cout << "Span assignment copy-constructed." << std::endl;
	return (*this);
}

Span::Span(const Span &orig): _size(orig._size), _int_vec(orig._int_vec)
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

Bureaucrat::FullSpanException::FullSpanException(unsigned int N)
{
	std::ostringstream out;
	out << "Cannot add more than " << N << " integers.";
	_msg = out.str();
}

Bureaucrat::FullSpanException::~FullSpanException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Bureaucrat::FullSpanException::what() const throw()
{
	return (this->_msg.c_str());
}

Bureaucrat::NoSpanException::NoSpanException()
{
	std::ostringstream out;
	out << "Two integers are needed to find Span.";
	_msg = out.str();
}

Bureaucrat::NoSpanException::~NoSpanException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Bureaucrat::NoSpanException::what() const throw()
{
	return (this->_msg.c_str());
}