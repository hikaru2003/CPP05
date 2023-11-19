/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 16:45:34 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(1)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
	if (grade_ < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade_ > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\33[37mThis is destructor\33[m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
	std::cout << "\33[37mThis is copy constructor\33[m" << std::endl;
	*this = rhs;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "\33[37mThis is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name_) = rhs.getName();
		this->grade_ = rhs.getGrade();
	}
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return this->name_;
}

int			Bureaucrat::getGrade() const
{
	return this->grade_;
}

void		Bureaucrat::increment_grade()
{
	if (grade_ <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade_--;
}

void		Bureaucrat::decrement_grade()
{
	if (grade_ >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade_++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		if (this->getGrade() <= form.getGradeToExecute())
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() <<std::endl; 
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}