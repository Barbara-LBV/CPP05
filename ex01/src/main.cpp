/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/06 11:36:10 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"
#include "../lib/Form.hpp"

int	main(void)
{
	try
	{
		Form	f("EB110", 1, 1);
		std::cout << f;
		Bureaucrat	john("John", 15);
		john.signForm(f);
		std::cout << "1. "<< john << std::endl;
		john.decrementGrade(1);
		std::cout << "2. "<< john << std::endl;
		john.signForm(f);
		john.incrementGrade(20);
		std::cout << "3. "<< john << std::endl;
		john.signForm(f);
		john.incrementGrade(1);
		std::cout << "4. "<< john << std::endl;
		john.signForm(f);
        john.incrementGrade(13);
		std::cout << "5. "<< john << std::endl;
		john.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}