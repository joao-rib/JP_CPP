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

class Span
{
private:
	std::vector<int> _int_vec;
	unsigned int	 _size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &orig);
	Span &operator = (const Span &orig);
	~Span();

	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

	void	addNumber(int num);
	void	addManyRandomNumbers(unsigned int num);

	int	&operator [] (long index);
	const int	&operator [] (long index) const;

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

	class OutOfBoundsException: public std::exception
	{
	private:
		std::string _msg;
	public:
		OutOfBoundsException(const Span &arr, long pos);
		virtual ~OutOfBoundsException() throw();
		virtual const char *what() const throw();
	};
};

#endif
