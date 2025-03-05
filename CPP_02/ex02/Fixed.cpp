#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	return(this->getRawBits() / 256);
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / 256);
}

int Fixed::getRawBits(void) const
{
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}

std::ostream& operator << (std::ostream& out, const Fixed& fp_num)
{
    out << fp_num.toFloat();
    return (out);
}

Fixed &Fixed::operator = (const Fixed &orig)
{
	if (this != &orig)
	{
		this->setRawBits(orig.getRawBits());
	}
	//std::cout << "Fixed copy assignment occurs" << std::endl;
	return (*this);
}

Fixed::Fixed(const Fixed &orig)
{
	*this = orig;
	//std::cout << "Fixed copy constructed!" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->setRawBits(roundf(num * 256));
	//std::cout << "Fixed default constructed as float!" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->setRawBits(num * 256);
	//std::cout << "Fixed default constructed as int!" << std::endl;
}

Fixed::Fixed(void)
{
	this->setRawBits(0);
	//std::cout << "Fixed default constructed!" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Fixed destructor here!" << std::endl;
}