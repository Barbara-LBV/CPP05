/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/06 12:43:44 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"
#include "../lib/Intern.hpp"

int	main(void)
{
	try
	{	
		Intern 		someRandomIntern;
		Bureaucrat	bob("Bobo", 137);		
		AForm 		*form = NULL;
		
		form = someRandomIntern.makeForm("Robotomy Request", "Bender1");
		if (form == NULL)
			return 0;
		bob.signForm(*form);	
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Intern 		someRandomIntern;
		Bureaucrat	bob("Bibi", 72);
		AForm 		*form;
		
		form = someRandomIntern.makeForm("Shrubbery Creation", "Bender2");
		if (form == NULL)
			return 0;
		bob.signForm(*form);	
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Intern 		someRandomIntern;
		Bureaucrat	bob("Bubu", 1);
		AForm 		*form;
		
		form = someRandomIntern.makeForm("Presidential Pardon", "Bender3");
		if (form == NULL)
			return 0;
		bob.signForm(*form);	
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Intern 		someRandomIntern;
		Bureaucrat	bob("Bebe", 1);		
		AForm 		*form;
		
		form = someRandomIntern.makeForm("Presidential pardon", "Bender4");
		if (form == NULL)
			return 0;
		bob.signForm(*form);	
		bob.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}