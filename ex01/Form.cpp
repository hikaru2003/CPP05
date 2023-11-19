/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:42:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:31:38 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default"), is_signed_(false), grade_to_sign_(1), grade_to_execute_(1)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
}

Form::Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute) : name_(name), is_signed_(is_signed), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
		throw (Form::GradeTooHighException());
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
	std::cout << "\33[37mThis is destructor\33[m" << std::endl;
}
Form::Form(const Form &rhs)
{
	std::cout << "\33[37mThis is copy constructor\33[m" << std::endl;
	*this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "\33[37mThis is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name_) = rhs.name_;
		this->is_signed_ = rhs.is_signed_;
		this->grade_to_sign_ = rhs.grade_to_sign_;
		this->grade_to_execute_ = rhs.grade_to_execute_; 
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os << "form informations" << std::endl;
	os << "name: " << rhs.getName() << std::endl;
	os << "is signed: " << rhs.getSigned() << std::endl;
	os << "grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (os);
}


std::string	Form::getName() const
{
	return this->name_;
}

bool		Form::getSigned() const
{
	return this->is_signed_;
}

int			Form::getGradeToSign() const
{
	return this->grade_to_sign_;
}

int			Form::getGradeToExecute() const
{
	return this->grade_to_execute_;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->is_signed_ = true;
}

void	Form::signForm(const Bureaucrat &bureaucrat)
{
	if (this->is_signed_ == true && bureaucrat.getGrade() <= this->getGradeToExecute())
		std::cout << bureaucrat.getName() << " signed " << this->name_ << std::endl;
	else if (this->is_signed_ == true)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name_ << " because grade is too low" << std::endl;
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name_ << " because form status is false" << std::endl;
}
