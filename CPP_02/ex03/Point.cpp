#include "Point.hpp"

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
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

/*Point &Point::operator = (const Point &orig)
{
	if (this != &orig)
		this->setCoord(orig.getX(), orig.getY());
	//std::cout << "Point copy assignment occurs" << std::endl;
	return (*this);
}*/

Point::Point(const Point &orig): _x(orig._x), _y(orig._y)
{
	//std::cout << "Point copy constructed!" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	//std::cout << "Point default constructed as float!" << std::endl;
}

Point::Point(void): _x(0), _y(0)
{
	//std::cout << "Point default constructed!" << std::endl;
}

Point::~Point(void)
{
	//std::cout << "Point destructor here!" << std::endl;
}