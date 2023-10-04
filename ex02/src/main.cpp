/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/04 14:05:30 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"

int	main(void)
{
	AForm			*form = NULL;
	form = new PresidentialPardonForm("28Z");
	
	try
	{
		Bureaucrat		bib("Jerry", -1);
		form->beSigned(bib);
		bib.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	form = NULL;
	
	Bureaucrat		bob("Bob", 1);
	Bureaucrat		phil("Phil", 40);
	Bureaucrat		luc("Luc", 150);

	try
	{
		form = new PresidentialPardonForm("28Z");
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		bob.executeForm(*form);
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new PresidentialPardonForm("28A");
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		form = new RobotomyRequestForm("28B");
		form->beSigned(bob);
		bob.executeForm(*form);
		form->beSigned(phil);

		phil.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		form = new ShrubberyCreationForm("28C");
		form->beSigned(bob);
		form->beSigned(phil);
		form->beSigned(luc);
		phil.executeForm(*form);
		bob.executeForm(*form);
		luc.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}