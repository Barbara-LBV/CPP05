/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:22 by root              #+#    #+#             */
/*   Updated: 2023/10/11 14:16:11 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << YELLOW "RobotomyRequestForm Default Constructor -> called" DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &b) : AForm("Robotomy Request Form", 72, 45)
{
    std::cout << YELLOW "RobotomyRequestForm Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &b)
{
     std::cout << YELLOW "RobotomyRequestForm Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _target = b._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED "RobotomyRequestForm Destructor -> called" DEFAULT << std::endl;
}

std::string const   RobotomyRequestForm::getTarget(void)const
{
    return (_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == 1 && executor.getGrade() <= getGradeExec())
    {
        std::cout << "   [Drilling noises]" DEFAULT << std::endl;
        if (std::rand() % 2)
		    std::cout << "Dear " << executor.getName() << ", the victim " << this->_target << " has been successfully robotomized" << std::endl;
	    else
		    std::cout << "The robotomization on " << this->_target << " may have completely failed." << std::endl;
    }
    else if (getSigned() == 1 && executor.getGrade() > getGradeExec())
    {
		throw AForm::CantExecuteForm();
    }
    else if (getSigned() == 0)
    {
        std::cout << "Form not signed." << std::endl;
		throw AForm::CantExecuteForm();
    }
}
