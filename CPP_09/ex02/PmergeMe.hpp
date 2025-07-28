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
	std::vector<int>	_vec_cnt;
	std::deque<int>		_deq_cnt;
	int*			_input;
	const size_t	_size;
	long			_start_time;
	long			_time1;
	long			_time2;

	int *const			&getInput() const;
	void	setInput(char **args);
	void	setTime(t_times option);

	std::vector<int>	order_vector(std::vector<int> above);
	std::deque<int>		order_deque(std::deque<int> above);

	template <typename T>
	void order_container(T& container, unsigned int layer, unsigned int pair_total); // WIP
	unsigned int	_last_layer;
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

template<typename T>
T&	min(T& a, T& b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T&	max(T& a, T& b)
{
	if (a > b)
		return a;
	return b;
}

template<typename T>
void PmergeMe::order_container(T& container, unsigned int layer, unsigned int pair_total) // WIP
{
	size_t s = container.size();
	// int pair_total = s / (2 * layer); // Odd numbers unaccounted for

	// Last layer
	if (pair_total < 2)
	{
		_last_layer = layer;
		return ;
	}

	// If Container's size is odd
	/*int Odd_Element = -1;
	if (s != pair_total * 2 * layer)
		Odd_Element = container.back(); // WIP must be the entire pair*/

	// Create main and pend

	// Recurse

	//if (Odd_Element > -1)
	//	pend_cnt.push_back(Odd_Element);

	// STEP 3: Jacobsthal WIP
	// 3.1: Jacobsthal numbers
	// 3.2: Insert b1, a1, a2, etc. to main
	// 3.3: Insert pairs from pend into main (Jacobstahl order, in reverse)
	//  main_vec.insert(std::lower_bound(main_vec.begin(), main_vec.end(), value), value);
	// 3.4: Insert remaining pends, if any
}

#endif
