#pragma once

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

#include <map>
#include <algorithm>
#include <typeinfo>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
	//std::map<std::string, float> _input;
	//unsigned int	 _size;
public:
	BitcoinExchange();
	//BitcoinExchange(std::string input);
	BitcoinExchange(const BitcoinExchange &orig);
	BitcoinExchange &operator = (const BitcoinExchange &orig);
	virtual ~BitcoinExchange();

	//unsigned int const	&size(void) const;
	//void					incSize(void);
	void				set_data(void);
	//void				set_input(std::string input);

	void		print_values(std::string input);

	class InvalidValueException: public std::exception
	{
	private:
		std::string _msg;
	public:
		InvalidValueException(std::string msg, std::string value);
		virtual ~InvalidValueException() throw();
		virtual const char *what() const throw();
	};
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

#endif
