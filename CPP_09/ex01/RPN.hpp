#pragma once

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdint.h>

#include <stack>
#include <algorithm>
#include <typeinfo>

class RPN
{
private:
	std::stack<int> _numbers;
	std::stack<char> _operators;
	void	set_stacks(std::string input);
	int		operation(char op, int fir, int sec);
public:
	RPN();
	RPN(std::string input);
	RPN(const RPN &orig);
	RPN &operator = (const RPN &orig);
	virtual ~RPN();

	void	print_result(void);

/*	class InvalidValueException: public std::exception
	{
	private:
		std::string _msg;
	public:
		InvalidValueException(std::string msg, std::string value);
		virtual ~InvalidValueException() throw();
		virtual const char *what() const throw();
	};*/
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
