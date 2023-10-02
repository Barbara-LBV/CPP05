/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:10 by root              #+#    #+#             */
/*   Updated: 2023/09/11 17:22:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << BLUE "PresidentialPardonForm Default Constructor -> called" DEFAULT << std::endl;
    checkGrade();
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
    checkGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &b)
{
    c << b.getTarget();
    return (c);
}

std::string const   PresidentialPardonForm ::getTarget(void)const
{
    return (_target);
}

void		PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    std::cout << "Dear " << executor.getName() << ", " << getName()
        << " have been forgiven by Zaphod Beeblebrox!!" << std::endl;
}