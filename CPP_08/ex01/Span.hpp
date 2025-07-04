#pragma once

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

#include <vector>
#include <list>
#include <algorithm>
#include <typeinfo>

template<typename T>
class Span
{
private:
	std::vector<int	_int_vec;
	unsigned int	_size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &orig);
	Span &operator = (const Span &orig);
	~Span();

	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	void	addNumber(int num);
	//void	addMultiNumbers(void);

	//T&	operator [] (long index);
	//const T&	operator [] (long index) const;

	class FullSpanException: public std::exception
	{
	private:
		std::string _msg;
	public:
		FullSpanException(unsigned int N);
		virtual ~FullSpanException() throw();
		virtual const char *what() const throw();
	};

	class NoSpanException: public std::exception
	{
	private:
		std::string _msg;
	public:
		NoSpanException();
		virtual ~NoSpanException() throw();
		virtual const char *what() const throw();
	};
};

#include "Span.tpp"

#endif
