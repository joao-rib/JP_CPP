#pragma once

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &orig);
	ScalarConverter &operator = (const ScalarConverter &orig);
	virtual ~ScalarConverter();
public:
	static void converter(std::string const &str);

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
