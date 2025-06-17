#include "ScalarConverter.hpp"

int ScalarConverter::toInt(void) const
{
	return(this->getRawBits() / 256);
}

float ScalarConverter::toFloat(void) const
{
	return ((float)this->getRawBits() / 256);
}

int ScalarConverter::getRawBits(void) const
{
	return (this->_num);
}

void ScalarConverter::setRawBits(int const raw)
{
	this->_num = raw;
}

ScalarConverter& ScalarConverter::min(ScalarConverter &n1, ScalarConverter &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

const ScalarConverter& ScalarConverter::min(const ScalarConverter &n1, const ScalarConverter &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

ScalarConverter& ScalarConverter::max(ScalarConverter &n1, ScalarConverter &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

const ScalarConverter& ScalarConverter::max(const ScalarConverter &n1, const ScalarConverter &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

bool ScalarConverter::operator == (const ScalarConverter& another) const
{
	return (this->_num == another._num);
}

bool ScalarConverter::operator != (const ScalarConverter& another) const
{
	return (this->_num != another._num);
}

bool ScalarConverter::operator > (const ScalarConverter& another) const
{
	return (this->_num > another._num);
}

bool ScalarConverter::operator >= (const ScalarConverter& another) const
{
	return (this->_num >= another._num);
}

bool ScalarConverter::operator < (const ScalarConverter& another) const
{
	return (this->_num < another._num);
}

bool ScalarConverter::operator <= (const ScalarConverter& another) const
{
	return (this->_num <= another._num);
}

ScalarConverter ScalarConverter::operator + (const ScalarConverter& amount) const
{
	//this->setRawBits(this->getRawBits() + amount.getRawBits());
	//return (ScalarConverter(this->getRawBits() + amount.getRawBits()));
	return (ScalarConverter(this->toFloat() + amount.toFloat()));
}

ScalarConverter ScalarConverter::operator - (const ScalarConverter& amount) const
{
	//this->setRawBits(this->getRawBits() - amount.getRawBits());
	//return (ScalarConverter(this->getRawBits() - amount.getRawBits()));
	return (ScalarConverter(this->toFloat() - amount.toFloat()));
}

ScalarConverter ScalarConverter::operator * (const ScalarConverter& amount) const
{
	//this->setRawBits(this->getRawBits() * amount.getRawBits());
	//return (ScalarConverter(this->getRawBits() * amount.getRawBits()));
	return (ScalarConverter(this->toFloat() * amount.toFloat()));
}

ScalarConverter ScalarConverter::operator / (const ScalarConverter& amount) const
{
	//this->setRawBits(this->getRawBits() / amount.getRawBits());
	//return (ScalarConverter(this->getRawBits() / amount.getRawBits()));
	return (ScalarConverter(this->toFloat() / amount.toFloat()));
}

ScalarConverter &ScalarConverter::operator ++ (void)
{
	//this->setRawBits(this->getRawBits() + 1);
	this->_num++;
	return (*this);
}

ScalarConverter ScalarConverter::operator ++ (int)
{
	ScalarConverter temp = *this;
	//this->setRawBits(this->getRawBits() + 1);
	this->_num++;
	return (temp);
}

ScalarConverter &ScalarConverter::operator -- (void)
{
	//this->setRawBits(this->getRawBits() - 1);
	this->_num--;
	return (*this);
}

ScalarConverter ScalarConverter::operator -- (int)
{
	ScalarConverter temp = *this;
	//this->setRawBits(this->getRawBits() - 1);
	this->_num--;
	return (temp);
}

std::ostream& operator << (std::ostream& out, const ScalarConverter& fp_num)
{
	out << fp_num.toFloat();
	return (out);
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &orig)
{
	if (this != &orig)
	{
		this->setRawBits(orig.getRawBits());
	}
	//std::cout << "ScalarConverter copy assignment occurs" << std::endl;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
	*this = orig;
	//std::cout << "ScalarConverter copy constructed!" << std::endl;
}

ScalarConverter::ScalarConverter(const float num)
{
	this->setRawBits(roundf(num * 256));
	//std::cout << "ScalarConverter default constructed as float!" << std::endl;
}

ScalarConverter::ScalarConverter(const int num)
{
	this->setRawBits(num * 256);
	//std::cout << "ScalarConverter default constructed as int!" << std::endl;
}

ScalarConverter::ScalarConverter(void)
{
	this->setRawBits(0);
	//std::cout << "ScalarConverter default constructed!" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "ScalarConverter destructor here!" << std::endl;
}