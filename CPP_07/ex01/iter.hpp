#pragma once

#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

template<typename T>
void	iter(T* arr_add, unsigned int len, void (*funct)(T&))
{
	for (unsigned int i = 0; i < len; i++)
		funct(arr_add[i]);
}

template<typename T>
void	iter(T* arr_add, unsigned int len, void (*funct)(const T&))
{
	for (unsigned int i = 0; i < len; i++)
		funct(arr_add[i]);
}

#endif
