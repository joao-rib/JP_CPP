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
//	Fixed left = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));
//	Fixed right = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()));
//	Fixed bottom = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()));
//	Fixed top = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()));
	Fixed tri_area = (a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY()))
					+ (c.getX() * (a.getY() - b.getY()));
	if (tri_area < 0)
		tri_area = tri_area * (-1);
	tri_area = tri_area / 2;
	return (tri_area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed bsp_tri_area = triangle_area(a, b, c);
	Fixed point_area1 = triangle_area(a, b, point);
	Fixed point_area2 = triangle_area(a, point, c);
	Fixed point_area3 = triangle_area(point, b, c);

	if (point_area1 == 0 || point_area2 == 0 || point_area3 == 0)
		return (false);

	Fixed point_area = point_area1 + point_area2 + point_area3;
	std::cout << bsp_tri_area << std::endl;
	std::cout << point_area << std::endl;
	if (point_area == bsp_tri_area)
		return (true);
	else
		return (false);
}
