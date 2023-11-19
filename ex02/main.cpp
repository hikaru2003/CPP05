/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:39 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:22:46 by hikaru           ###   ########.fr       */
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
		
		shrubbery.beSigned(hikaru);
		presidential.beSigned(hikaru);
		robotomy.beSigned(hikaru);
		
		shrubbery.signAForm(hikaru);
		presidential.signAForm(hikaru);
		robotomy.signAForm(hikaru);
		
		hikaru.executeForm(shrubbery);
		hikaru.executeForm(presidential);
		// hikaru.executeForm(robotomy);
		// hikaru.executeForm(robotomy);
		// hikaru.executeForm(robotomy);
		// hikaru.executeForm(robotomy);
		// hikaru.executeForm(robotomy);
		// hikaru.executeForm(robotomy);

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
