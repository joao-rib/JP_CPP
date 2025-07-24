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
#include <sys/time.h>

#include <vector>
#include <deque>
#include <algorithm>
#include <typeinfo>

enum t_times
{
	TIME_1,
	TIME_2,
	TIME_START
};

class PmergeMe
{
private:
	std::vector<int>	_first;
	std::deque<int>		_second;
	int*			_input;
	const size_t	_size;
	long			_start_time;
	long			_time1;
	long			_time2;

	int *const			&getInput() const;
	void	setInput(char **args);
	void	setTime(t_times option);

	void	order_vector(std::vector<int> above);
	void	order_deque(std::deque<int> above);
public:
	PmergeMe();
	PmergeMe(char** args, int arg_num);
	PmergeMe(const PmergeMe &orig);
	PmergeMe &operator = (const PmergeMe &orig);
	virtual ~PmergeMe();

	size_t const	&getSize() const;
	long			getTime(t_times option) const;

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
