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
	T&				_value;
	unsigned int	_size;
public:
	Array(); //WIP empty array
	Array(unsigned int n); //WIP n elements, initialised by default
	Array(const Array &orig); //WIP deep copy
	Array &operator = (const Array &orig); //WIP deep copy
	~Array(); //WIP build it

	unsigned int	size(void) const;

	//WIP build it
	class OutOfBoundsException: public std::exception
	{
	private:
		std::string _msg;
	public:
		OutOfBoundsException(const Array &paper, const std::string &reason);
		virtual ~OutOfBoundsException() throw();
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

//std::ostream& operator << (std::ostream& out, const Array& paper);

//WIP new[] operator
//WIP subscript operator []

#endif
