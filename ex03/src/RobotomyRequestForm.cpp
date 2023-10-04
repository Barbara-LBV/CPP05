/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:22 by root              #+#    #+#             */
/*   Updated: 2023/10/04 16:53:19 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 145, 137), _target(target)
{
    std::cout << YELLOW "RobotomyRequestForm Default Constructor -> called" DEFAULT << std::endl;
    checkGrade();
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &b) : AForm("Robotomy Request Form", 145, 137)
{
    std::cout << YELLOW "RobotomyRequestForm Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &b)
{
     std::cout << YELLOW "RobotomyRequestForm Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _target = b._target;
    checkGrade();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << YELLOW "RobotomyRequestForm Destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &b)
{
    c << b.getTarget();
    return (c);
}

std::string const   RobotomyRequestForm::getTarget(void)const
{
    return (_target);
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    std::cout << "   [Drilling noises]" DEFAULT << std::endl;
   if (std::rand() % 2)
		std::cout << "Dear " << executor.getName() << ", the victim " << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "The robotomization on " << this->_target << " may have completely failed." << std::endl;
}
