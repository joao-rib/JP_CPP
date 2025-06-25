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

struct Data
{
	int			serial_num;
	std::string	name;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &orig);
	Serializer &operator = (const Serializer &orig);
	virtual ~Serializer();
public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);

	class OutsideScopeException: public std::exception
	{
	private:
		std::string _msg;
	public:
		OutsideScopeException(const std::string &reason);
		virtual ~OutsideScopeException() throw();
		virtual const char *what() const throw();
	};
};

#endif
