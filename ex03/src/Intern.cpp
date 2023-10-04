/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:23:41 by root              #+#    #+#             */
/*   Updated: 2023/10/04 16:58:15 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Intern.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << BOLD "Intern Default Constructor -> called" DEFAULT << std::endl;
};

Intern::Intern(Intern const &i)
{
    std::cout << BLUE "Intern Copy Constructor -> called" DEFAULT << std::endl;
    *this = i;
}

Intern::~Intern()
{
    std::cout << BOLD "Intern Destructor -> called" DEFAULT << std::endl;
}

Intern &Intern::operator=(Intern const &b)
{
    if (this != &b)
        *this = b;
    return (*this);
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    AForm *f = NULL;
    int		i;
    
	std::string	option[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	
	for (i = 0 ; i < 3 ; i++)
	{
		if (option[i] == name)
			break ;
	}

	switch(i)
	{
		case 0:
            std::cout << "Intern creates " << name << " form." << std::endl;
			f = new PresidentialPardonForm(target);
            break ;
		case 1:
			std::cout << "Intern creates " << name << " form." << std::endl;
            f = new RobotomyRequestForm(target);
            break ;
		case 2:
			std::cout << "Intern creates " << name << " form." << std::endl;
            f = new ShrubberyCreationForm(target);
            break ;
		case 3:
			std::cout << "Intern coudn't create " << name << " form cause it doens't exist." << std::endl;
            f = NULL;
			break ;
	}
    return (f);
}