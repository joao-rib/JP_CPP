#pragma once

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Fixed
{
private:
	int _num;
	const static int _bits = 8;
public:
	Fixed();
	Fixed(const Fixed &orig);
	Fixed &operator = (const Fixed &orig);
    ~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
