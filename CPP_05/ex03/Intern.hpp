#pragma once

#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern &orig);
	Intern &operator = (const Intern &orig);
	virtual ~Intern();

	AForm*	makeForm(std::string const &name, std::string const &target);

	class NoFormException: public std::exception
	{
	private:
		std::string _msg;
	public:
		NoFormException(std::string const &name);
		virtual ~NoFormException() throw();
		virtual const char *what() const throw();
	};
};

#endif
