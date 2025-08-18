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

	template <typename T>
	void order_container(T& container, unsigned int layer);
	template<typename T>
	void order_small(T& container);

	unsigned int	_last_layer;
	unsigned int	_comparisons_vec;
	unsigned int	_comparisons_deq;
	unsigned int	_comp_tmp;
public:
	PmergeMe();
	PmergeMe(char** args, int arg_num);
	PmergeMe(const PmergeMe &orig);
	PmergeMe &operator = (const PmergeMe &orig);
	virtual ~PmergeMe();

	size_t const	&getSize() const;
	size_t			getLayers() const;
	size_t			getCompVec() const;
	size_t			getCompDeq() const;
	long			getTime(t_times option) const;

	void	print_unsorted();
	void	print_sorted();
	int		diffJacobsthal(int seq_num);
	int		maxComparisons();
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
void	push_back_elements(T& container, T& buff_cnt, size_t pair_num, size_t element_size)
{
	for (unsigned int i = 0; i < element_size; i++)
		buff_cnt.push_back(container[(pair_num * element_size) + i]);
}

template<typename T>
void	push_back_rest(T& src, T& dst, size_t start_pos)
{
	for (unsigned int i = start_pos; i < src.size(); i++)
		dst.push_back(src[i]);
}

template<typename T>
void	swap_elements(T& container, unsigned int start, size_t element_size)
{
	size_t end = start + element_size;
	while (start < end)
	{
		int buff = container[start];
		container[start] = container[start + element_size];
		container[start + element_size] = buff;
		start++;
	}
}

template<typename T>
size_t	insert_elements(T& dst, T& src, size_t pos, size_t element_size)
{
	if (element_size == 0)
		throw InputException(": Invalid use of insert_elements()");

	// Compare max value from pend group with max values from main groups
	size_t comparison_total = 0;
	size_t max_pos = ((pos + 1) * element_size) - 1;
	typename T::iterator it = dst.end();
	for (unsigned int i = 0; i < dst.size(); i += element_size)
	{
		if (dst[i + element_size - 1] > src[max_pos])
		{
			it = dst.begin() + i;
			comparison_total++;
			break;
		}
		comparison_total++;
	}

	// Insert pend group into main container
	dst.insert(it, src.begin() + (pos * element_size), src.begin() + max_pos + 1);
	
	return (comparison_total);
}

template<typename T>
void PmergeMe::order_small(T& container)
{
	// Swap numbers if needed
	if (container[0] > container[1])
		::swap_elements(container, 0, 1);
	_comp_tmp++;

	// Create main and pend
	T pend_cnt;
	T main_cnt;
	::push_back_elements(container, main_cnt, 0, 1); // b1
	::push_back_elements(container, main_cnt, 1, 1); // a1

	// Add the odd elements into the pend, then insert into the main
	if (this->getSize() == 3)
	{
		::push_back_rest(container, pend_cnt, 1);
		_comp_tmp += ::insert_elements(main_cnt, pend_cnt, 1, 1);
	}

	// Replace values in container, from main
	for (unsigned int i = 0; i < this->getSize(); i++)
		container[i] = main_cnt[i];
}

template<typename T>
void PmergeMe::order_container(T& container, unsigned int layer)
{
	size_t pair_size = 1;
	for (unsigned int i = 0; i < layer; i++)
		pair_size *= 2;
	size_t pair_total = this->getSize() / pair_size;

	// Last layer
	if (pair_total < 2)
	{
		this->_last_layer = layer;
		if (this->getSize() < 4)
			this->order_small(container);
		return ;
	}

	// If Container's size is odd, then this variable is smaller than _size
	unsigned int Odd_Element_pos = pair_total * pair_size;

	// Swap numbers/pairs where needed
	for (unsigned int i = 0; i < (pair_total * pair_size); i += pair_size)
	{
		if (container[i + (pair_size / 2) - 1] > container[i + pair_size - 1])
			::swap_elements(container, i, pair_size / 2);
		_comp_tmp++;
	}

	// Recurse
	this->order_container(container, layer + 1);

	// Create main and pend
	T pend_cnt;
	T main_cnt;
	::push_back_elements(container, main_cnt, 0, pair_size / 2); // b1
	::push_back_elements(container, main_cnt, 1, pair_size / 2); // a1
	for (unsigned int i = 2; i < (pair_total * 2); i++) 
	{
		::push_back_elements(container, pend_cnt, i, pair_size / 2); // Remaining b
		::push_back_elements(container, main_cnt, ++i, pair_size / 2); // Remaining a
	}

	// Add the odd elements into the pend
	if (Odd_Element_pos < this->getSize())
		::push_back_rest(container, pend_cnt, Odd_Element_pos);

	// Insert pend elements into the main
	int j = 2;
	size_t c = 0;
	size_t p = pend_cnt.size() / (pair_size / 2);
	while (c < p)
	{
		for (unsigned int i = this->diffJacobsthal(j); i > 0; i--)
		{
			if ((c + i) > p)
				continue ;
			_comp_tmp += ::insert_elements(main_cnt, pend_cnt, c + i - 1, pair_size / 2);
		}
		c += this->diffJacobsthal(j);
		j++;
	}

	// Add remaining elements from the pend
	if (p * (pair_size / 2) < pend_cnt.size())
		::push_back_rest(pend_cnt, main_cnt, p * (pair_size / 2));

	// Replace values in container, from main
	for (unsigned int i = 0; i < this->getSize(); i++)
		container[i] = main_cnt[i];
}

#endif
