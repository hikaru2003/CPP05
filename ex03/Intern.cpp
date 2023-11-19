/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:36 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:42:31 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(/* args */)
{
	std::cout << "\33[37mIntern default constructor called\33[m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\33[37mIntern default destructor called\33[m" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	std::cout << "\33[37mIntern copy constructor called\33[m" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "\33[37mIntern copy assignment operator called\33[m" << std::endl;
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm*	createForms[] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
	AForm*	rtnForm = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			rtnForm = createForms[i];
		}
		else
			delete createForms[i];
	}
	if (rtnForm)
		return (rtnForm);
	std::cerr << "Intern cannot create " << form << std::endl;
	return NULL;
}
