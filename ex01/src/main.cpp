/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/11/23 12:41:22 by blefebvr         ###   ########.fr       */
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
		std::cout << std::endl;
		Bureaucrat	john("John", 151);
		std::cout << "1. "<< john;
		john.signForm(f);
		john.decrementGrade(1);
		std::cout << std::endl;
		std::cout << "2. "<< john;
		john.signForm(f);
		john.incrementGrade(15);
		std::cout << std::endl;
		std::cout << "3. "<< john;
		john.signForm(f);
		john.incrementGrade(-5);
		std::cout << std::endl;
		std::cout << "4. "<< john;
		john.signForm(f);
        john.incrementGrade(-150);
		std::cout << std::endl;
		std::cout << "5. "<< john;
		john.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	//{
	//	Form	f("EB110", 1, 1);
	//	std::cout << f;
	//	std::cout << std::endl;
	//	Bureaucrat	john("John", 15);
	//	std::cout << "1. "<< john;
	//	john.signForm(f);
	//	john.decrementGrade(1);
	//	std::cout << std::endl;
	//	std::cout << "2. "<< john;
	//	john.signForm(f);
	//	john.incrementGrade(15);
	//	std::cout << std::endl;
	//	std::cout << "3. "<< john;
	//	john.signForm(f);
	//	john.incrementGrade(-5);
	//	std::cout << std::endl;
	//	std::cout << "4. "<< john;
	//	john.signForm(f);
    //    john.incrementGrade(-150);
	//	std::cout << std::endl;
	//	std::cout << "5. "<< john;
	//	john.signForm(f);
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	return 0;
}