#include "Point.hpp"

Fixed Point::getX(void) const
{
	return (this->_x);
}

void Point::setX(Fixed const &raw)
{
	this->_x = raw;
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

void Point::setY(Fixed const &raw)
{
	this->_y = raw;
}

/*std::ostream& operator << (std::ostream& out, const Point& fp_num)
{
	out << fp_num.toFloat();
	return (out);
}*/

bool Point::operator != (const Point& another) const
{
	return ((this->_x != another._x) || (this->_y != another._y));
}

bool Point::operator == (const Point& another) const
{
	return ((this->_x == another._x) && (this->_y == another._y));
}

Point &Point::operator = (const Point &orig)
{
	if (this != &orig)
	{
		this->setX(orig.getX());
		this->setY(orig.getY());
	}
	//std::cout << "Point copy assignment occurs" << std::endl;
	return (*this);
}

Point::Point(const Point &orig)
{
	*this = orig;
	//std::cout << "Point copy constructed!" << std::endl;
}

Point::Point(const float x, const float y)
{
	this->setX(Fixed(x));
	this->setY(Fixed(y));
	//std::cout << "Point default constructed as float!" << std::endl;
}

Point::Point(void)
{
	this->setX(Fixed(0));
	this->setY(Fixed(0));
	//std::cout << "Point default constructed!" << std::endl;
}

Point::~Point(void)
{
	//std::cout << "Point destructor here!" << std::endl;
}