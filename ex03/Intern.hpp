/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:03 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:40:44 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
private:
	/* data */
public:
	Intern(/* args */);
	~Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);
	AForm* makeForm(std::string form, std::string target);
};

