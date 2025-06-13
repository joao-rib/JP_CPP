#pragma once

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int	_grade_sign;
	const int	_grade_exec;
	bool 		_signature;
public:
	AForm();
	AForm(std::string const &name, int grade_sign, int grade_exec);
	AForm(const AForm &orig);
	AForm &operator = (const AForm &orig);
	virtual ~AForm();

	std::string const		&getName(void) const;
	int	const 				&getSignGrade(void) const;
	int	const 				&getExecGrade(void) const;
	bool const				&getSignature(void) const;
	void					setSignature(bool sign);

	void	beSigned(Bureaucrat &bureau);
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooHighException(const AForm &paper, const std::string &reason);
		virtual ~GradeTooHighException() throw();
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooLowException(const AForm &paper, const std::string &reason);
		virtual ~GradeTooLowException() throw();
		virtual const char *what() const throw();
	};

	class CannotSignException: public std::exception
	{
	private:
		std::string _msg;
	public:
		CannotSignException(const AForm &paper, const std::string &reason);
		virtual ~CannotSignException() throw();
		virtual const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream& out, const AForm& paper);

#endif
