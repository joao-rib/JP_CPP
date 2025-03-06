#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed left(Fixed::minThree(a.getX(), b.getX(), c.getX())); //WIP Fazer isto no Point
	Fixed right(Fixed::maxThree(a.getX(), b.getX(), c.getX())); //WIP Fazer isto no Point
	Fixed bottom(Fixed::minThree(a.getX(), b.getX(), c.getX())); //WIP Fazer isto no Point
	Fixed top(Fixed::maxThree(a.getX(), b.getX(), c.getX())); //WIP Fazer isto no Point

	//Fixed left = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));

	if (point.getX() <= left || point.getX() >= right || point.getY() >= top || point.getY() <= bottom)
		return (false);
}
