#pragma once

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

#include <stack>
#include <algorithm>
#include <typeinfo>

class PmergeMe
{
private:
	std::   <int>	_first;
	std::   <int>	_second;
	char**	_input;
	size_t	_size;
	double	_start_time;
	double	_time1;
	double	_time2;
	//void 	validate_input();
public:
	PmergeMe();
	PmergeMe(char** input);
	PmergeMe(const PmergeMe &orig);
	PmergeMe &operator = (const PmergeMe &orig);
	virtual ~PmergeMe();

	//void				setInput(std::string input);
	//std::string const	&getInput(void) const;

	void	print_unsorted();
	void	print_sorted();
};

class InputException: public std::exception
{
private:
	std::string _msg;
public:
	InputException(std::string msg);
	virtual ~InputException() throw();
	virtual const char *what() const throw();
};

#endif
