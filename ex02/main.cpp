/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:39 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 16:53:18 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	hikaru("hikaru", 1);
		ShrubberyCreationForm	shrubbery("shr");
		PresidentialPardonForm 	presidential("pres");
		RobotomyRequestForm		robotomy("rob");
		
		std::cout << hikaru << std::endl;
		std::cout << shrubbery;
		std::cout << presidential;
		std::cout << robotomy;
		
		hikaru.signForm(shrubbery);
		hikaru.signForm(presidential);
		hikaru.signForm(robotomy);
		
		hikaru.executeForm(shrubbery);
		hikaru.executeForm(presidential);
		hikaru.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q ex02");
// }
