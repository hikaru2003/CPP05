/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:42:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/10/05 13:06:32 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("AForm"), is_signed_(false), grade_to_sign_(1), grade_to_execute_(1)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
}

AForm::AForm(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute) : name_(name), is_signed_(is_signed), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute)
{
	std::cout << "\33[37mThis is constructor\33[m" << std::endl;
	if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
		throw (AForm::GradeTooHighException());
	if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{
	std::cout << "\33[37mThis is destructor\33[m" << std::endl;
}
AForm::AForm(const AForm &rhs)
{
	std::cout << "\33[37mThis is copy constructor\33[m" << std::endl;
	*this = rhs;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "\33[37mThis is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		setName(rhs.getName());
		setSigned(rhs.getSigned());
		setGradeToSign(rhs.getGradeToSign());
		setGradeToExecute(rhs.getGradeToExecute());
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os << "AForm informations" << std::endl;
	os << "name: " << rhs.getName() << std::endl;
	os << "is signed: " << rhs.getSigned() << std::endl;
	os << "grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (os);
}


std::string	AForm::getName() const
{
	return this->name_;
}

bool		AForm::getSigned() const
{
	return this->is_signed_;
}

int			AForm::getGradeToSign() const
{
	return this->grade_to_sign_;
}

int			AForm::getGradeToExecute() const
{
	return this->grade_to_execute_;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->is_signed_ = true;
}

void	AForm::signAForm(const Bureaucrat &bureaucrat)
{
	if (this->is_signed_ == true && bureaucrat.getGrade() <= this->getGradeToExecute())
		std::cout << bureaucrat.getName() << " signed " << this->name_ << std::endl;
	else if (this->is_signed_ == true)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name_ << " because grade is too low" << std::endl;
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name_ << " because Aform status is false" << std::endl;
}

void	AForm::setName(std::string name)
{
	const_cast<std::string &>(this->name_) = name;
}

void	AForm::setSigned(bool sign)
{
	this->is_signed_ = sign;
}

void	AForm::setGradeToSign(int sign)
{
	this->grade_to_sign_ = sign;
}

void	AForm::setGradeToExecute(int sign)
{
	this->grade_to_execute_ = sign;
}
