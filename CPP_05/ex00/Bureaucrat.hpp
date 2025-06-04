#pragma once

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Bureaucrat
{
protected:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &orig);
	Bureaucrat &operator = (const Bureaucrat &orig);
	virtual ~Bureaucrat();

	std::string		getName(void) const;
	int				getGrade(void);
	void			incGrade(void);
	void			decGrade(void);
};

//std::ostream& operator << (std::ostream& out, const Fixed& fp_num); WIP name
//std::ostream& operator << (std::ostream& out, const Fixed& fp_num); WIP grade

#endif
