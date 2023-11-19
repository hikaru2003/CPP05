/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:28:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/10/05 14:45:25 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name_;
	bool				is_signed_;
	int					grade_to_sign_;
	int					grade_to_execute_;
	
public:
	AForm();
	AForm(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute);
	virtual ~AForm();
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &rhs);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		setName(std::string name);
	void		setSigned(bool sign);
	void		setGradeToSign(int sign);
	void		setGradeToExecute(int sign);
	
	void	beSigned(const Bureaucrat &bureaucrat);
	void			signAForm(const Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat &executor) const = 0;

	// exception
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too high";};
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw() {return "Grade is too low";};
	};
	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw() {return "Not signed";};
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);