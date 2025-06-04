#pragma once

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <sstream>
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

	std::string const		&getName(void) const;
	int	const 				&getGrade(void) const;
	void					incGrade(void);
	void					decGrade(void);

/*	Bureaucrat &operator ++ (void); //pre
	Bureaucrat operator ++ (int); //post
	Bureaucrat &operator -- (void); //pre
	Bureaucrat operator -- (int); //post*/

	class GradeTooHighException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooHighException(const Bureaucrat &bureau);
		virtual ~GradeTooHighException() throw();
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooLowException(const Bureaucrat &bureau);
		virtual ~GradeTooLowException() throw();
		virtual const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureau);

#endif
