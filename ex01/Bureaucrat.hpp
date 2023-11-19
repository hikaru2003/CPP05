/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:45 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 16:16:13 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name_;
	int					grade_;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	std::string	getName() const;
	int			getGrade() const;
	void		increment_grade();
	void		decrement_grade();
	void		signForm(Form &form);

	// exception function
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too high";};
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too low";};
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);
