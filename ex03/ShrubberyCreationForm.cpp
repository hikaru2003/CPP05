/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:06:18 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:35:33 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target_("default")
{
	std::cout << "\33[37mShrubberyCreationForm default constructor called\33[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false, 145, 137), target_(target)
{
	std::cout << "\33[37mShrubberyCreationForm constructor called\33[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
{
	std::cout << "\33[37m37mShrubberyCreationForm This is copy constructor\33[m" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "\33[37m37mShrubberyCreationForm This is copy assignment operator\33[m" << std::endl;
	if (this != &rhs)
	{
		this->target_ = rhs.getTarget();
		AForm::operator=(rhs);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\33[37mShrubberyCreationForm destructor\33[m" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->target_;
}

void	ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::NotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::ofstream ofs(this->getTarget() + "_shrubbery");
		if (!ofs)
		{
			std::cerr << "cannot create file" << std::endl;
			return ;
		}
		ofs << "	   _-_" << std::endl;
		ofs << "    /~~   ~~\\" << std::endl;
		ofs << " /~~         ~~\\" << std::endl;
		ofs << "{               }" << std::endl;
		ofs << " \\  _-     -_  /" << std::endl;
		ofs << "   ~  \\\\ //  ~" << std::endl;
		ofs << "_- -   | | _- _" << std::endl;
		ofs << "  _ -  | |   -_" << std::endl;
		ofs << "//////// \\\\\\\\\\\\\\\\" << std::endl;
		ofs.close();
		std::cout << this->getTarget() << "_shrubbery created" << std::endl;
	}
}
