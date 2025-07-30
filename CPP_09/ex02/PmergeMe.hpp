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

	//std::vector<int>	order_vector(std::vector<int> above);
	//std::deque<int>		order_deque(std::deque<int> above);

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
void	swap_pairs(T& container, unsigned int start, size_t element_size)
{
	size_t end = start + element_size;
	while (start < end)
	{
		T buff = container[start];
		container[start] = container[start + element_size];
		container[start + element_size] = buff;
		start++;
	}
}

template<typename T>
void	insert_pairs(T& main_cnt, T& pend_cnt, size_t pos, size_t element_size) // WIP
{
	size_t true_pos = (pos * element_size) + (element_size - 1);
	typename T::iterator it = std::lower_bound(main_cnt.begin(), main_cnt.end(), pend_cnt[true_pos]) - element_size + 1; // WIP end()?

	for (unsigned int i = 0; i < element_size; i++)
		main_cnt.insert(it - i, pend_cnt[true_pos - i]);
}

template<typename T>
void	push_back_pairs(T& container, T& buff_cnt, size_t pair_num, size_t element_size)
{
	for (unsigned int i = 0; i < element_size; i++)
		buff_cnt.push_back(container[(pair_num * element_size) + i]);
}

template<typename T>
void	push_back_rest(T& container, T& buff_cnt, size_t start_pos)
{
	for (unsigned int i = start_pos; i < buff_cnt.size(); i++)
		buff_cnt.push_back(container[i]);
}

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

	// If Container's size is odd, then this variable is smaller than _size
	unsigned int Odd_Element_pos = pair_total * pair_size;

	// Swap numbers/pairs where needed
	for (unsigned int i = 0; i < pair_total; i += pair_size)
	{
		if (container[i + (pair_size / 2) - 1] > container[i + pair_size - 1])
			::swap_pairs(container, i, pair_size / 2);
	}

	// Recurse
	this->order_container(container, layer + 1);

	// Create main and pend
	T pend_cnt;
	T main_cnt;
	::push_back_pairs(container, main_cnt, 0, pair_size / 2); // b1
	::push_back_pairs(container, main_cnt, 1, pair_size / 2); // a1
	for (unsigned int i = 2; i < (pair_total * pair_size); i++) 
	{
		::push_back_pairs(container, pend_cnt, i, pair_size / 2); // Remaining b
		::push_back_pairs(container, main_cnt, ++i, pair_size / 2); // Remaining a
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
		for (unsigned int i = diffJacobsthal(j); i > 0; i--)
		{
			if ((c + i) > p)
				break ;
			::insert_pairs(main_cnt, pend_cnt, c + i - 1, pair_size / 2);
		}
		c += diffJacobsthal(j);
		j++;
	}

	// Insert remaining pends, if any
	for (unsigned int i = p - c; i > 0; i--)
		::insert_pairs(main_cnt, pend_cnt, c + i - 1, pair_size / 2);

	// Add remaining elements into the pend
	if (p * (pair_size / 2) < pend_cnt.size())
		::push_back_rest(main_cnt, pend_cnt, p * (pair_size / 2));

	// Replace values in container, from main
	for (unsigned int i = 0; i < main_cnt.size(); i++)
		container[i] = main_cnt[i];
}

#endif
