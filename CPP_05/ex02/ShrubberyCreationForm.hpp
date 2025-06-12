#pragma once

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Bureaucrat;

class ShrubberyCreationForm
{
private:
	const std::string _name;
	const int	_grade_sign;
	const int	_grade_exec;
	bool 		_signature;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &name, int grade_sign, int grade_exec);
	ShrubberyCreationForm(const ShrubberyCreationForm &orig);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &orig);
	virtual ~ShrubberyCreationForm();

	std::string const		&getName(void) const;
	int	const 				&getSignGrade(void) const;
	int	const 				&getExecGrade(void) const;
	bool const				&getSignature(void) const;
	void					setSignature(bool sign);

	virtual void	beSigned(Bureaucrat &bureau);

	class GradeTooHighException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooHighException(const ShrubberyCreationForm &paper, const std::string &reason);
		virtual ~GradeTooHighException() throw();
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooLowException(const ShrubberyCreationForm &paper, const std::string &reason);
		virtual ~GradeTooLowException() throw();
		virtual const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const ShrubberyCreationForm& paper);

#endif
