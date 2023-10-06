/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/06 11:55:45 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"

int	main(void)
{
	AForm			*form = NULL;
	form = new ShrubberyCreationForm("28Z");
	
	try
	{
		Bureaucrat		bib("Jerry", 45);
		bib.signForm(*form);
		bib.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	std::cout << std::endl;

	try
	{
		Bureaucrat		luc("Marc", 5);
		form = new PresidentialPardonForm("28A");
		luc.signForm(*form);
		luc.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	std::cout << std::endl;
	
	try
	{
		Bureaucrat		luc("Luc", 137);
		form = new RobotomyRequestForm("28B");
		luc.signForm(*form);
		luc.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form;
	return (0);
}