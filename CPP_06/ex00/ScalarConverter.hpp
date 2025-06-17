#pragma once

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &orig);
	ScalarConverter &operator = (const ScalarConverter &orig);
	virtual ~ScalarConverter();
public:
	static void converter(std::string const &str);

	class NoCharException: public std::exception
	{
	private:
		std::string _msg;
	public:
		NoCharException(const std::string &reason);
		virtual ~NoCharException() throw();
		virtual const char *what() const throw();
	};
};

#endif
