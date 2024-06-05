/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:12:31 by root              #+#    #+#             */
/*   Updated: 2023/10/11 18:02:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Form.hpp"

Form::Form() : _name("Default Form"), _gradeSigned(150), _gradeExec(150), _signed(false)
{
    std::cout << GREEN "Form Default Constructor -> called" DEFAULT << std::endl;
}

Form::Form(std::string const &name, int const gradeSigned, int const gradeExec) : _name(name), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
    std::cout << GREEN "Form Parametric Constructor -> called" DEFAULT << std::endl;
    _signed = false;
    checkGrades();
}

Form::Form(Form const &b) : _gradeSigned(150), _gradeExec(150)
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
    checkGrades();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const Form &f)
{
    c << f.getName() << " Form has to be signed by a grade "<< f.getGradeSigned()
      << " and execute by a grade " << f.getGradeExec() << ", the Form is "
      << ((f.getSigned()) ? "" : "not ") << "signed" << std::endl;
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

void   Form::checkGrades(void)const
{
    if (getGradeExec() < Bureaucrat::_highestGrade || getGradeSigned() < Bureaucrat::_highestGrade)
		throw Form::GradeTooHighException();
	else if (getGradeExec() > Bureaucrat::_lowestGrade || getGradeSigned() > Bureaucrat::_lowestGrade )
		throw Form::GradeTooLowException();
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() <= getGradeSigned())
        setSigned(1);
	else
    {
		throw Form::GradeTooLowException();
    }
}