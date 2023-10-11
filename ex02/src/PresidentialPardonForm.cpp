/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:10 by root              #+#    #+#             */
/*   Updated: 2023/10/06 15:38:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << YELLOW "PresidentialPardonForm Default Constructor -> called" DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &b) : AForm("Presidential Pardon Form", 25, 5)
{
    std::cout << YELLOW "PresidentialPardonForm Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED "PresidentialPardonForm Destructor -> called" DEFAULT << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &b)
{
     std::cout << YELLOW "PresidentialPardonForm Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _target = b._target;
    return (*this);
}

std::string const   PresidentialPardonForm ::getTarget(void)const
{
    return (_target);
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == 1 && executor.getGrade() <= getGradeExec())
    {
        std::cout << "Dear " << executor.getName() << ", " << getTarget()
        << " have been forgiven by Zaphod Beeblebrox!!" << std::endl;
    }
    else if (getSigned() == 0)
    {
        std::cout << "Form not signed." << std::endl;
		throw AForm::CantExecuteForm();
    }
    else if (getSigned() == 1 && executor.getGrade() > getGradeExec())
    {
		throw AForm::CantExecuteForm();
    }
}