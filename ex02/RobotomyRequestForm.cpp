/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:04:30 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:36:31 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target_("default")
{
	std::cout << "\33[37mRobotomyRequestForm default constructor called\33[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", false, 72, 45), target_(target)
{
	std::cout << "\33[37mRobotomyRequestForm constructor called\33[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
{
	std::cout << "\33[37mRobotomyRequestForm This is copy constructor\33[m" << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "\33[37mRobotomyRequestForm This is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		this->target_ = rhs.getTarget();
		AForm::operator=(rhs);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\33[37mRobotomyRequestForm destructor\33[m" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->target_;
}

void	RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::NotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
