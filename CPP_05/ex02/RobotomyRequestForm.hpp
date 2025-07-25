#pragma once

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <ctime>

//#include <iostream>
//#include <sstream>
//#include <locale>
//#include <iomanip>
//#include <cstdlib>

//class Bureaucrat;

class RobotomyRequestForm: public AForm
{
private:
//	const std::string _name;
//	const int	_grade_sign;
//	const int	_grade_exec;
//	bool 		_signature;
	const std::string _target;
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(const RobotomyRequestForm &orig);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &orig);
	virtual ~RobotomyRequestForm();

//	std::string const		&getName(void) const;
//	int	const 				&getSignGrade(void) const;
//	int	const 				&getExecGrade(void) const;
//	bool const				&getSignature(void) const;
//	void					setSignature(bool sign);

//	void	beSigned(Bureaucrat &bureau);
	virtual void	execute(Bureaucrat const &executor) const;

/*	class GradeTooHighException: public std::exception
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

	class CannotExecuteException: public std::exception
	{
	private:
		std::string _msg;
	public:
		CannotExecuteException(const AForm &paper, const std::string &reason);
		virtual ~CannotExecuteException() throw();
		virtual const char *what() const throw();
	};	*/
};

std::ostream& operator << (std::ostream& out, const RobotomyRequestForm& paper);

#endif
