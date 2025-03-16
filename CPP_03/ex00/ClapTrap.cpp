#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits got called, son!" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}

Fixed &Fixed::operator = (const Fixed &orig)
{
	if (this != &orig)
	{
		this->_num = orig.getRawBits();
	}
	std::cout << "Fixed copy assignment!" << std::endl;
	return (*this);
}

Fixed::Fixed(const Fixed &orig)
{
	*this = orig;
	std::cout << "Fixed copy constructed!" << std::endl;
}

Fixed::Fixed(void)
{
	this->_num = 0;
	std::cout << "Fixed default constructed!" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed destructor here!" << std::endl;
}

