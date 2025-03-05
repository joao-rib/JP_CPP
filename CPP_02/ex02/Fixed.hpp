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
	~Fixed();

	Fixed &operator = (const Fixed &orig);

	bool operator == (const Fixed &another) const;
	/*Fixed &operator > (const Fixed &orig);
	Fixed &operator < (const Fixed &orig);
	Fixed &operator >= (const Fixed &orig);
	Fixed &operator <= (const Fixed &orig);
	Fixed &operator == (const Fixed &orig);
	Fixed &operator != (const Fixed &orig);*/

	Fixed operator + (const Fixed &amount) const;
	/*Fixed &operator + (const Fixed &orig);
	Fixed &operator - (const Fixed &orig);
	Fixed &operator * (const Fixed &orig);
	Fixed &operator / (const Fixed &orig);*/

	Fixed &operator ++ (void); //pre
	Fixed &operator ++ (int); //post WIP why "int"?
	/*pre-increment
	post-increment
	pre-decrement
	post-decrement*/

	static Fixed &min(Fixed &n1, Fixed &n2);
	static const Fixed &min(const Fixed &n1, const Fixed &n2);
	/*min
	min const
	max
	max const*/

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator << (std::ostream& out, const Fixed& fp_num);

#endif
