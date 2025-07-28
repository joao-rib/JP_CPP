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
	void order_container(T& container, unsigned int layer); // WIP
	unsigned int	_last_layer;
public:
	PmergeMe();
	PmergeMe(char** args, int arg_num);
	PmergeMe(const PmergeMe &orig);
	PmergeMe &operator = (const PmergeMe &orig);
	virtual ~PmergeMe();

	size_t const	&getSize() const;
	size_t const	&getLayers() const;
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
void	swap_pairs(T& container, unsigned int start, size_t pair_half_size)
{
	size_t end = start + pair_half_size
	while (start < end)
	{
		T buff = container[start];
		container[start] = container[start + pair_half_size];
		container[start + pair_half_size] = buff;
		start++;
	}
}

/*template<typename T>
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
}*/

template<typename T>
void PmergeMe::order_container(T& container, unsigned int layer) // WIP
{
	size_t pair_size = layer;
	for (unsigned int i = 0; i < layer; i++)
		pair_size *= 2;
	size_t pair_total = this->getSize() / pair_size; // Odd numbers unaccounted for?

	// Last layer
	if (pair_total < 2)
	{
		_last_layer = layer;
		return ;
	}

	// If Container's size is odd, then this variable is different from 0
	unsigned int Odd_Element_pos = this->getSize() - (pair_total * pair_size);

	// Swap numbers/pairs where needed
	for (unsigned int i = 0; i < pair_total; i += pair_size)
	{
		if (container[i + (pair_size / 2) - 1] > container[i + pair_size - 1])
			::swap_pairs(container, i, pair_size / 2);
	}

	// Recurse
	this->order_container(container, layer + 1);

	// Create main and pend
	std::T::T pend_cnt;
	std::T::T main_cnt;
	T::iterator it = container.begin();
	main_cnt = push_back(*it); // b1 // WIP must be the entire pair
	main_cnt = push_back(*(++it)); // a1 // WIP must be the entire pair
	it++;
	for (unsigned int i = 2; i < (pair_total * pair_size); i += 2, it++) // WIP must be the entire pair
	{
		pend_cnt.push_back(push_back(*it));
		main_cnt.push_back(push_back(*(++it)));
	}

	// Add the odd element into the pend
	if (Odd_Element > 0)
		pend_cnt.push_back(Odd_Element); // WIP must be the entire pair

	// Insert pend elements into the main
	int j = 2;
	size_t c = 0;
	size_t p = pend_cnt.size();
	while (c < p)
	{
		for (unsigned int i = diffJacobsthal(j); i >= 0; i--)
		{
			if (i > p)
				break ;
			main_cnt.insert(std::lower_bound(main_cnt.begin(), main_cnt.end(), pend_cnt[i]), pend_cnt[i]); // WIP must be the entire pair
		}
		c += diffJacobsthal(j);
		j++;
	}

	// Insert remaining pends, if any
	while (--p >= c)
		main_cnt.insert(std::lower_bound(main_cnt.begin(), main_cnt.end(), pend_cnt[p]), pend_cnt[p]); // WIP must be the entire pair

	// Replace values in container, from main
	for (unsigned int i = 0; i < main_cnt.size(); i++)
		container[i] = main_cnt[i]; // WIP Does it work between pairs and values?
}

#endif
