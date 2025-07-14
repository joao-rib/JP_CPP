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
	std::map<std::string, float> _input;
	unsigned int	 _size;
public:
	BitcoinExchange();
	BitcoinExchange(std::string input);
	BitcoinExchange(const BitcoinExchange &orig);
	BitcoinExchange &operator = (const BitcoinExchange &orig);
	virtual ~BitcoinExchange();

	void	store_data(void);
	void	store_input(std::string input);

	void	print_values(void);

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
