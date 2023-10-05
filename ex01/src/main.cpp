/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/05 14:14:43 by blefebvr         ###   ########.fr       */
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
		std::cout << john << std::endl;
		john.decrementGrade(1);
		std::cout << john << std::endl;
		john.signForm(f);
		john.incrementGrade(1);
		std::cout << john << std::endl;
		john.signForm(f);
		john.incrementGrade(1);
		std::cout << john << std::endl;
		john.signForm(f);
        john.incrementGrade(13);
		std::cout << john << std::endl;
		john.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//try
	//{
	//	Form	f("EB111", 1, 0);
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << std::endl;


	//try
	//{
	//	Form	f("EB112", 1, 151);
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << std::endl;


	//try
	//{
	//	Form	f("EB113", 151, 1);
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << std::endl;


	//try
	//{
	//	Bureaucrat	john("John", 10);
	//	Form		f("EB114", 150, 150);

	//	std::cout << f << std::endl;
	//	f.beSigned(john);
	//	john.signForm(f);
	//	std::cout << f << std::endl;
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << std::endl;


	//try
	//{
	//	Bureaucrat	joe("Joe", 10);
	//	Form		f("EB115", 1, 1);

	//	std::cout << f << std::endl;
	//	f.beSigned(joe);
	//	joe.signForm(f);
	//	std::cout << f << std::endl;
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	return 0;
}