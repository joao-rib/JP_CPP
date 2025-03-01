#pragma once

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class Fixed
{
private:
	int _num;
	const static int _bits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &orig);
	Fixed &operator = (const Fixed &orig);
    ~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

#endif
