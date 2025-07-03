#pragma once

#ifndef EASYFIND_H
#define EASYFIND_H

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
typename T::iterator	easyfind(T& int_container, int num);

class NoOccurrenceException: public std::exception
{
private:
	std::string _msg;
public:
	NoOccurrenceException(const std::string reason, int num);
	~NoOccurrenceException() throw();
	const char *what() const throw();
};

#include "easyfind.tpp"

#endif
