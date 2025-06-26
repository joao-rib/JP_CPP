#pragma once

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

template<typename T>
void	swap(T& a, T& b)
{
	T buff = a;
	a = b;
	b = buff;
}

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

#endif
