/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:10:39 by hikaru            #+#    #+#             */
/*   Updated: 2023/11/19 14:06:25 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("a", 100);
		a.increment_grade();
		std::cout << a << std::endl;
		Bureaucrat	b("b", 1);
		b.increment_grade();
		std::cout << b << std::endl;
		// Bureaucrat	b("b", 1000);
		// b.increment_grade();
		// std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q ex00");
// }
