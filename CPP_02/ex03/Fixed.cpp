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

Fixed& Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

Fixed& Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

bool Fixed::operator == (const Fixed& another) const
{
	return (this->_num == another._num);
}

bool Fixed::operator != (const Fixed& another) const
{
	return (this->_num != another._num);
}

bool Fixed::operator > (const Fixed& another) const
{
	return (this->_num > another._num);
}

bool Fixed::operator >= (const Fixed& another) const
{
	return (this->_num >= another._num);
}

bool Fixed::operator < (const Fixed& another) const
{
	return (this->_num < another._num);
}

bool Fixed::operator <= (const Fixed& another) const
{
	return (this->_num <= another._num);
}

Fixed Fixed::operator + (const Fixed& amount) const
{
	//this->setRawBits(this->getRawBits() + amount.getRawBits());
	//return (Fixed(this->getRawBits() + amount.getRawBits()));
	return (Fixed(this->toFloat() + amount.toFloat()));
}

Fixed Fixed::operator - (const Fixed& amount) const
{
	//this->setRawBits(this->getRawBits() - amount.getRawBits());
	//return (Fixed(this->getRawBits() - amount.getRawBits()));
	return (Fixed(this->toFloat() - amount.toFloat()));
}

Fixed Fixed::operator * (const Fixed& amount) const
{
	//this->setRawBits(this->getRawBits() * amount.getRawBits());
	//return (Fixed(this->getRawBits() * amount.getRawBits()));
	return (Fixed(this->toFloat() * amount.toFloat()));
}

Fixed Fixed::operator / (const Fixed& amount) const
{
	//this->setRawBits(this->getRawBits() / amount.getRawBits());
	//return (Fixed(this->getRawBits() / amount.getRawBits()));
	return (Fixed(this->toFloat() / amount.toFloat()));
}

Fixed &Fixed::operator ++ (void)
{
	//this->setRawBits(this->getRawBits() + 1);
	this->_num++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp = *this;
	//this->setRawBits(this->getRawBits() + 1);
	this->_num++;
	return (temp);
}

Fixed &Fixed::operator -- (void)
{
	//this->setRawBits(this->getRawBits() - 1);
	this->_num--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed temp = *this;
	//this->setRawBits(this->getRawBits() - 1);
	this->_num--;
	return (temp);
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