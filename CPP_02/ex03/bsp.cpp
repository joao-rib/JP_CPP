#include "Point.hpp"

/*Fixed distY(Point const p1, Point const p2)
{
	if (p1.getY() > p2.getY())
		return (p1.getX() - p2.getX());
	else
		return (p2.getY() - p1.getY());
}

Fixed distX(Point const p1, Point const p2)
{
	if (p1.getX() > p2.getX())
		return (p1.getX() - p2.getX());
	else
		return (p2.getX() - p1.getX());
}*/

Fixed triangle_area(Point const a, Point const b, Point const c)
{
	Fixed left = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));
	Fixed right = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()));
	Fixed bottom = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()));
	Fixed top = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()));

	return ((top - bottom) * (right - left) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed bsp_tri_area = triangle_area(a, b, c);
	Fixed point_area;

	point_area = triangle_area(a, b, point) + triangle_area(a, point, c) + triangle_area(point, b, c);
	std::cout << bsp_tri_area << std::endl;
	std::cout << point_area << std::endl;
	if (point_area == bsp_tri_area)
		return (true);
	else
		return (false);
}
