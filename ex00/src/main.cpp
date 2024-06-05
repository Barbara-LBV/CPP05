/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/11/22 15:59:19 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	bill = Bureaucrat("Bill", 0);
		std::cout << bill << std::endl;
		bill.decrementGrade(1);
		bill.checkGrade();
		std::cout << bill << std::endl;
		bill.incrementGrade(1);
		std::cout << bill << std::endl;
		bill.incrementGrade(1);
		std::cout << bill << std::endl;
        bill.incrementGrade(1);
		std::cout << bill << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		bob = Bureaucrat("Bob", 150);
		std::cout << bob << std::endl;
		bob.incrementGrade(1);
		std::cout << bob << std::endl;
		bob.decrementGrade(1);
		std::cout << bob << std::endl;
		bob.decrementGrade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//std::cout << std::endl;


	//try
	//{
	//	Bureaucrat		bud = Bureaucrat("Bud", 0);
	//	std::cout << bud << std::endl;
	//	bud.decrementGrade(1);
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << std::endl;

	//try
	//{
	//	Bureaucrat  billie = Bureaucrat("Billie", 151);
	//	std::cout << billie << std::endl;
	//	billie.incrementGrade(1);
    //    std::cout << billie << std::endl;
	//}
	//catch (std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	return 0;
}