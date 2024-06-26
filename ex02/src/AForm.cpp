/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:12:31 by root              #+#    #+#             */
/*   Updated: 2023/10/24 14:49:15 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/AForm.hpp"

AForm::AForm() : _name("Default Form"), _gradeSigned(150), _gradeExec(150), _signed(false)
{
    std::cout << GREEN "AForm Default Constructor -> called" DEFAULT << std::endl;
}

AForm::AForm(std::string const &name, int const gradeSigned, int const gradeExec) : _name(name), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
    std::cout << GREEN "AForm Parametric Constructor -> called" DEFAULT << std::endl;
    _signed = false;
}

AForm::AForm(AForm const &b) : _gradeSigned(150), _gradeExec(150)
{
    std::cout << GREEN "AForm Copy Constructor -> called" DEFAULT << std::endl;
    _signed = b._signed;
}

AForm::~AForm()
{
    std::cout << RED "AForm Destructor -> called" DEFAULT << std::endl;
}

AForm &AForm::operator=(AForm const &b)
{
    std::cout << GREEN "AForm Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _signed = b._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const AForm &f)
{
    c << f.getName() << " has to be signed by a grade "<< f.getGradeSigned()
      << " and executed by a grade " << f.getGradeExec() << ", the Form is "
      << ((f.getSigned()) ? "" : "not ") << "signed" << std::endl;
    return (c);
}

std::string const    &AForm::getName(void)const
{
    return (this->_name);
}

int const &AForm::getGradeSigned(void)const
{
    return (this->_gradeSigned);
}

int const &AForm::getGradeExec(void)const
{
    return (this->_gradeExec);
}

bool const  &AForm::getSigned(void)const
{
    return (_signed);
}

void    AForm::setSigned(int i)
{
    _signed = i;
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() <= getGradeSigned() && _signed == false)
        setSigned(1);
    else
    {
		throw AForm::GradeTooLowException();
    }
}