#pragma once

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

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
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack &orig);
	MutantStack &operator = (const MutantStack &orig);
	virtual ~MutantStack();

	//WIP investigar reverse_iterators

	iterator begin(void);
	iterator end(void);
	const_iterator begin(void) const;
	const_iterator end(void) const;

	reverse_iterator rbegin(void);
	reverse_iterator rend(void);
	const_reverse_iterator rbegin(void) const;
	const_reverse_iterator rend(void) const;

};

#include "MutantStack.tpp"

#endif
