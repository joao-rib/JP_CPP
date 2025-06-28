#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

template<typename T>
class Array
{
private:
	T&				_values;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &orig);
	Array &operator = (const Array &orig);
	~Array();

	unsigned int	size(void) const;

	T&	operator [] (unsigned int index);

	class OutOfBoundsException: public std::exception
	{
	private:
		std::string _msg;
	public:
		OutOfBoundsException(const Array &arr, unsigned int pos);
		virtual ~OutOfBoundsException() throw();
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

//std::ostream& operator << (std::ostream& out, const Array& paper);

//WIP new[] operator
//WIP subscript operator []

#endif
