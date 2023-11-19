/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:39 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:23:02 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	hikaru("hikaru", 51);
		Form		form("form", false, 100, 50);
		std::cout << "name: " << hikaru.getName() << ", score: " << hikaru.getGrade() << std::endl;
		std::cout << form;
		form.beSigned(hikaru);
		form.signForm(hikaru);
		hikaru.increment_grade();
		form.beSigned(hikaru);
		form.signForm(hikaru);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q ex01");
// }
