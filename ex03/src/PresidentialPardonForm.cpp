/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:10 by root              #+#    #+#             */
/*   Updated: 2023/10/05 16:40:20 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << BLUE "PresidentialPardonForm Default Constructor -> called" DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &b) : AForm("Presidential Pardon Form", 25, 5)
{
    std::cout << BLUE "PresidentialPardonForm Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << BLUE "PresidentialPardonForm Destructor -> called" DEFAULT << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &b)
{
     std::cout << BLUE "PresidentialPardonForm Assignement Operator -> called" DEFAULT << std::endl;
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
    if (executor.getGrade() == getGradeExec() && executor.getGrade() == getGradeSigned())
    {
        std::cout << "Dear " << executor.getName() << ", " << getName()
        << " have been forgiven by Zaphod Beeblebrox!!" << std::endl;
    }
    else if (executor.getGrade() != getGradeExec() && executor.getGrade() == getGradeSigned())
    {
		    throw AForm::CantExecuteForm();
    }
    else if (executor.getGrade() == getGradeExec() && executor.getGrade() != getGradeSigned())
    {
        if (executor.getGrade() < getGradeSigned())
		    throw AForm::GradeTooHighException();
	    else if (executor.getGrade() > getGradeExec())
		    throw AForm::GradeTooLowException();
    }
     else
    {
		throw AForm::CantExecuteForm();
    }
}