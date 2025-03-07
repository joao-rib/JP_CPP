#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed left = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));
	Fixed right = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()));
	Fixed bottom = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()));
	Fixed top = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()));

	if (point.getX() <= left || point.getX() >= right || point.getY() >= top || point.getY() <= bottom)
		return (false);
	
	Point topLeft(left.toFloat(), top.toFloat());
	Point topRight(right.toFloat(), top.toFloat());
	Point bottomLeft(left.toFloat(), bottom.toFloat());
	Point bottomRight(right.toFloat(), bottom.toFloat());
}
