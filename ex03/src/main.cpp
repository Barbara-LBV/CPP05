/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:25 by root              #+#    #+#             */
/*   Updated: 2023/10/04 16:58:04 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"
#include "../lib/Intern.hpp"

int	main(void)
{
	{	
		Intern someRandomIntern;
		Bureaucrat		bob("bob", 1);
		AForm *form;
		form = someRandomIntern.makeForm("Robotomy Request", "Bender");
		if (form == NULL)
			return 0;
		form->execute(bob);
		delete form;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat		bob("bob", 1);
		AForm *form;
		form = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
		if (form == NULL)
			return 0;
		form->execute(bob);
		delete form;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat		bob("bob", 1);
		AForm *form;
		form = someRandomIntern.makeForm("Presidential Pardon", "Bender");
		if (form == NULL)
			return 0;
		form->execute(bob);
		delete form;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat		bob("bob", 1);
		AForm *form;
		form = someRandomIntern.makeForm("Presidential pardon", "Bender");
		if (form == NULL)
			return 0;
		form->execute(bob);
		delete form;
	}
	return 0;
}