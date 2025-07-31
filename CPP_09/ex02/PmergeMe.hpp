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
	unsigned int	_last_layer;
public:
	PmergeMe();
	PmergeMe(char** args, int arg_num);
	PmergeMe(const PmergeMe &orig);
	PmergeMe &operator = (const PmergeMe &orig);
	virtual ~PmergeMe();

	size_t const	&getSize() const;
	size_t			getLayers() const;
	long			getTime(t_times option) const;

	void	print_unsorted();
	void	print_sorted();
	int		diffJacobsthal(int seq_num);
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
		int buff = container[start];
		container[start] = container[start + element_size];
		container[start + element_size] = buff;
		start++;
	}
}

template<typename T>
void	insert_pairs(T& dst, T& src, size_t pos, size_t element_size)
{
	size_t max_pos = ((pos + 1) * element_size) - 1;
	/*std::cout << std::endl;
	std::cout << "(initial) dst.size() = " << dst.size() << std::endl;
	std::cout << "(initial) dst: ";*/
	for (unsigned int i = 0; i < dst.size(); i++)
		std::cout << dst[i] << " ";
	/*std::cout << std::endl;
	std::cout << "pos = " << pos << std::endl;
	std::cout << "max_pos = " << max_pos << std::endl;
	std::cout << "src[max_pos] = " << src[max_pos] << std::endl;*/
	typename T::iterator it = std::lower_bound(dst.begin(), dst.end(), src[max_pos]); // WIP end()?
	// WIP 19 did not go to the right spot // Search manually instead of using lower_bound
	//std::cout << "*it (real) = " << *it << std::endl;
	for (unsigned int i = 1; i < element_size; i++)
		it--;
	/*std::cout << "*it (begin) = " << *it << std::endl;
	std::cout << "src.begin() + (pos * element_size) = " << *(src.begin() + (pos * element_size)) << std::endl;
	std::cout << "src.begin() + max_pos = " << *(src.begin() + max_pos) << std::endl;*/
	dst.insert(it, src.begin() + (pos * element_size), src.begin() + max_pos + 1);
	/*std::cout << std::endl;
	std::cout << "dst.size() = " << dst.size() << std::endl;
	std::cout << "dst: ";
	for (unsigned int i = 0; i < dst.size(); i++)
		std::cout << dst[i] << " ";
	std::cout << std::endl;*/
}

template<typename T>
void	push_back_pairs(T& container, T& buff_cnt, size_t pair_num, size_t element_size)
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
void PmergeMe::order_container(T& container, unsigned int layer)
{
	size_t pair_size = 1;
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
	for (unsigned int i = 0; i < (pair_total * pair_size); i += pair_size)
	{
		if (container[i + (pair_size / 2) - 1] > container[i + pair_size - 1])
			::swap_pairs(container, i, pair_size / 2);
	}
	std::cout << "PRE-recursion container (layer " << layer << "): " << std::endl;
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
	// Recurse
	this->order_container(container, layer + 1);

	std::cout << '\n' << "POST-recursion container (layer " << layer << "): " << std::endl;
	for (unsigned int i = 0; i < this->getSize(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;

	// Create main and pend
	T pend_cnt;
	T main_cnt;
	::push_back_pairs(container, main_cnt, 0, pair_size / 2); // b1
	::push_back_pairs(container, main_cnt, 1, pair_size / 2); // a1
	for (unsigned int i = 2; i < (pair_total * 2); i++) 
	{
		::push_back_pairs(container, pend_cnt, i, pair_size / 2); // Remaining b
		::push_back_pairs(container, main_cnt, ++i, pair_size / 2); // Remaining a
	}

	/*std::cout << std::endl;
	std::cout << "pair_total = " << pair_total << std::endl;
	std::cout << "pair_size = " << pair_size << std::endl;
	std::cout << "main_cnt.size() = " << main_cnt.size() << std::endl;
	std::cout << "main_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < main_cnt.size(); i++)
		std::cout << main_cnt[i] << " ";
	std::cout << std::endl;
	std::cout << "pend_cnt.size() = " << pend_cnt.size() << std::endl;
	std::cout << "pend_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < pend_cnt.size(); i++)
		std::cout << pend_cnt[i] << " ";
	std::cout << std::endl;*/

	// Add the odd elements into the pend
	if (Odd_Element_pos < this->getSize())
		::push_back_rest(container, pend_cnt, Odd_Element_pos);

	/*std::cout << std::endl;
	std::cout << "Odd_Element_pos = " << Odd_Element_pos << std::endl;
	std::cout << "main_cnt.size() = " << main_cnt.size() << std::endl;
	std::cout << "main_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < main_cnt.size(); i++)
		std::cout << main_cnt[i] << " ";
	std::cout << std::endl;
	std::cout << "pend_cnt.size() = " << pend_cnt.size() << std::endl;
	std::cout << "pend_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < pend_cnt.size(); i++)
		std::cout << pend_cnt[i] << " ";
	std::cout << std::endl;*/

	// Insert pend elements into the main
	int j = 2;
	size_t c = 0;
	size_t p = pend_cnt.size() / (pair_size / 2);
	while (c < p)
	{
		for (unsigned int i = this->diffJacobsthal(j); i > 0; i--)
		{
			if ((c + i) > p)
				break ;
			::insert_pairs(main_cnt, pend_cnt, c + i - 1, pair_size / 2);
		}
		c += this->diffJacobsthal(j);
		j++;
	}

	std::cout << std::endl;
	std::cout << "p = " << p << "; c = " << c << std::endl;
	std::cout << "Remaining (p - c) = " << (p - c) << std::endl;
	std::cout << "main_cnt.size() = " << main_cnt.size() << std::endl;
	std::cout << "main_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < main_cnt.size(); i++)
		std::cout << main_cnt[i] << " ";
	std::cout << std::endl;
	std::cout << "pend_cnt.size() = " << pend_cnt.size() << std::endl;
	std::cout << "pend_cnt (layer " << layer << "): ";
	for (unsigned int i = 0; i < pend_cnt.size(); i++)
		std::cout << pend_cnt[i] << " ";
	std::cout << std::endl;

	// Insert remaining pends, if any
	for (unsigned int i = p - c; i > 0; i--) // WIP certainly wrong
		::insert_pairs(main_cnt, pend_cnt, c + i - 1, pair_size / 2);

	// Add remaining elements from the pend
	if (p * (pair_size / 2) < pend_cnt.size())
		::push_back_rest(pend_cnt, main_cnt, p * (pair_size / 2));

	// Replace values in container, from main
	for (unsigned int i = 0; i < this->getSize(); i++)
		container[i] = main_cnt[i];
}

#endif
