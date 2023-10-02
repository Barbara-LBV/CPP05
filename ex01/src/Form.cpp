/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:12:31 by root              #+#    #+#             */
/*   Updated: 2023/09/07 15:57:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Form.hpp"

Form::Form() : _name(""), _gradeSigned(1), _gradeExec(1), _signed(false)
{
    std::cout << GREEN "Form Default Constructor -> called" DEFAULT << std::endl;
}

Form::Form(std::string const &name, int const gradeSigned, int const gradeExec) : _name(name), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
    std::cout << GREEN "Form Parametric Constructor -> called" DEFAULT << std::endl;

    _signed = false;
   checkGrade();
}

Form::Form(Form const &b) : _gradeSigned(1), _gradeExec(1)
{
    std::cout << GREEN "Form Copy Constructor -> called" DEFAULT << std::endl;
    Form(b._name, b._gradeSigned, b._gradeExec);
    _signed = b._signed;
}

Form::~Form()
{
    std::cout << RED "Form Destructor -> called" DEFAULT << std::endl;
}

Form &Form::operator=(Form const &b)
{
    std::cout << GREEN "Form Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
    {
        Form(b._name, b._gradeSigned, b._gradeExec);
        _signed = b._signed;
    }
    checkGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const Form &f)
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

std::string const    &Form::getName(void)const
{
    return (this->_name);
}

int const &Form::getGradeSigned(void)const
{
    return (this->_gradeSigned);
}

int const &Form::getGradeExec(void)const
{
    return (this->_gradeExec);
}

bool const  &Form::getSigned(void)const
{
    return (_signed);
}

void    Form::setSigned(int i)
{
    this->_signed = i;
}

void   Form::checkGrade(void)const
{
    if (getGradeExec() < Form::_highestGrade || getGradeSigned() < Form::_highestGrade)
		throw Form::GradeTooHighException();
	else if (getGradeExec() > Form::_lowestGrade || getGradeSigned() > Form::_lowestGrade )
		throw Form::GradeTooLowException();
}

void    Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() < 150 || b.getGrade() > 0)
        setSigned(1);
    else
    {
        if (b.getGrade() < 1)
		    throw Form::GradeTooHighException();
	    else if (b.getGrade() > 150)
		    throw Form::GradeTooLowException();
    }
}