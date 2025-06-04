#pragma once

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Bureaucrat: std::exception
{
protected:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &orig);
	virtual ~Bureaucrat();

	std::string const		&getName(void) const;
	int	const 				&getGrade(void) const;
	void					incGrade(void);
	void					decGrade(void);

/*	Bureaucrat &operator ++ (void); //pre
	Bureaucrat operator ++ (int); //post
	Bureaucrat &operator -- (void); //pre
	Bureaucrat operator -- (int); //post*/
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureau);

#endif
