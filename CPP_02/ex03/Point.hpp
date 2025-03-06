#pragma once

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &orig);
	~Point();

	Point &operator = (const Point &orig);

	bool operator == (const Point &another) const;
	bool operator != (const Point &another) const;

	Fixed getX(void) const;
	void setX(Fixed const &raw);
	Fixed getY(void) const;
	void setY(Fixed const &raw);
};

//std::ostream& operator << (std::ostream& out, const Point& fp_num);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
