/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:28:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 16:15:56 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name_;
	bool				is_signed_;
	int					grade_to_sign_;
	int					grade_to_execute_;
	
public:
	Form();
	Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute);
	~Form();
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	
	void	beSigned(const Bureaucrat &bureaucrat);

	// exception
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too high";};
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too low";};
	};
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);