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
	static int _bits;
public:
	Fixed();
    ~Fixed();
	// copy
	// assign
	int getRawBits(void) const;
	void setRawBits(int const raw) const;
};

#endif
