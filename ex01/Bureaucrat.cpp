/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:30:40 by hikaru           ###   ########.fr       */
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
	this->grade_--;
	if (grade_ < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void		Bureaucrat::decrement_grade()
{
	this->grade_++;
	if (grade_ > 150)
		throw (Bureaucrat::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}
