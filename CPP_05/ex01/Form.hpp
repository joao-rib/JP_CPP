#pragma once

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int	_grade_sign;
	const int	_grade_exec;
	bool 		_signature;
public:
	Form();
	Form(std::string const &name, int grade_sign, int grade_exec);
	Form(const Form &orig);
	Form &operator = (const Form &orig);
	virtual ~Form();

	std::string const		&getName(void) const;
	int	const 				&getSignGrade(void) const;
	int	const 				&getExecGrade(void) const;
	bool const				&getSignature(void) const;
	void					setSignature(bool sign);

	void	beSigned(Bureaucrat &bureau);

	class GradeTooHighException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooHighException(const Form &paper, const std::string &reason);
		virtual ~GradeTooHighException() throw();
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooLowException(const Form &paper, const std::string &reason);
		virtual ~GradeTooLowException() throw();
		virtual const char *what() const throw();
	};

	class CannotSignException: public std::exception
	{
	private:
		std::string _msg;
	public:
		CannotSignException(const Form &paper, const std::string &reason);
		virtual ~CannotSignException() throw();
		virtual const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const Form& paper);

#endif
