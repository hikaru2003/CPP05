/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:56:27 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 16:32:34 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), target_("default")
{
	std::cout << "\33[37mPresidentialPardonForm default constructor called\33[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", false, 25, 5), target_(target)
{
	std::cout << "\33[37mPresidentialPardonForm constructor called\33[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
{
	std::cout << "\33[37mPresidentialPardonForm This is copy constructor\33[m" << std::endl;
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "\33[37mPresidentialPardonForm This is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		this->target_ = rhs.getTarget();
		AForm::operator=(rhs);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\33[37mPresidentialPardonForm destructor\33[m" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->target_;
}
void	PresidentialPardonForm::execute() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
