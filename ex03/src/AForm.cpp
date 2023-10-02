/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:12:31 by root              #+#    #+#             */
/*   Updated: 2023/09/11 15:54:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/AForm.hpp"

AForm::AForm() : _name(""), _gradeSigned(1), _gradeExec(1), _signed(false)
{
    std::cout << GREEN "AForm Default Constructor -> called" DEFAULT << std::endl;
}

AForm::AForm(std::string const &name, int const gradeSigned, int const gradeExec) : _name(name), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
    std::cout << GREEN "AForm Parametric Constructor -> called" DEFAULT << std::endl;
    _signed = false;

   checkGrade();
}

AForm::AForm(AForm const &b) : _gradeSigned(1), _gradeExec(1)
{
    std::cout << GREEN "AForm Copy Constructor -> called" DEFAULT << std::endl;
    //AForm(b._name, b._gradeSigned, b._gradeExec);
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
    {
        //AForm(b._name, b._gradeSigned, b._gradeExec);
        _signed = b._signed;
    }
    checkGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const AForm &f)
{
    c << f.getName() << std::endl;
    c << f.getGradeExec() << std::endl;
    c << f.getGradeSigned() << std::endl;
    c << f.getSigned() << std::endl;
    /*std::cout << MAGENTA << f.getName() << DEFAULT << std::endl;
    std::cout << MAGENTA << f.getGradeExec() << DEFAULT << std::endl;
    std::cout << MAGENTA << f.getGradeSigned() << DEFAULT << std::endl;
    std::cout << MAGENTA << f.getSigned() << DEFAULT << std::endl;*/
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
    this->_signed = i;
}

void   AForm::checkGrade(void)const
{
    if (getGradeExec() < AForm::_highestGrade || getGradeSigned() < AForm::_highestGrade)
		throw AForm::GradeTooHighException();
	else if (getGradeExec() > AForm::_lowestGrade || getGradeSigned() > AForm::_lowestGrade )
		throw AForm::GradeTooLowException();
}

void    AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() < 150 || b.getGrade() > 0)
    {
        setSigned(1);
        execute(b);
    }
    else
    {
        if (b.getGrade() < 1)
		    throw Bureaucrat::GradeTooHighException();
	    else if (b.getGrade() > 150)
		    throw Bureaucrat::GradeTooLowException();
    }
}